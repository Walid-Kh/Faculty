#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <ctype.h>
#include <sys/shm.h>
int semid;
int shmid;

struct msgbuf
{
    long mtype;
    char message[256];
};
union Semun
{
    int val;               /* Value for SETVAL */
    struct semid_ds *buf;  /* Buffer for IPC_STAT, IPC_SET */
    unsigned short *array; /* Array for GETALL, SETALL */
    struct seminfo *__buf; /* Buffer for IPC_INFO (Linux-specific) */
};
void conv(char *msg, int size)
{
    int i;
    for (i = 0; i < size; ++i)
        if (islower(msg[i]))
            msg[i] = toupper(msg[i]);
        else if (isupper(msg[i]))
            msg[i] = tolower(msg[i]);
}
void up(int semid)
{
    struct sembuf v;
    v.sem_flg = !IPC_NOWAIT;
    v.sem_num = 0;
    v.sem_op = 1;
    if (semop(semid, &v, 1) == -1)
    {
        printf("\nerror in upping the semaphore");
        exit(0);
    }
}
void down(int semid)
{
    struct sembuf p;
    p.sem_flg = !IPC_NOWAIT;
    p.sem_num = 0;
    p.sem_op = -1;
    if (semop(semid, &p, 1) == -1)
    {
        printf("error in downing the semaphore");
        exit(-1);
    }
}
void server(int semid)
{
    void *shmadd = shmat(shmid, (const void *)0, 0);
    while (1)
    {
        down(semid); 
        char message[256];
        strcpy(message, (char *)shmadd);
        conv(message, strlen(message));
        strcpy((char *)shmadd, message);
        up(semid);
    }
}
void handler(int sig)
{
    // remember to remove semaphore and shared memory
    semctl(semid, 0, IPC_RMID);
    shmctl(shmid, IPC_RMID, (struct shmid_ds *)0);
    exit(0);
}

int main(int argc, char **argv)
{
    signal(SIGINT, handler);
    
    key_t semkey = ftok("semkey", 66);
    
    key_t shmkey = ftok("shmkey", 67);

    semid = semget(semkey, 1, IPC_CREAT | 0666);
    shmid = shmget(shmkey, 256, IPC_CREAT | 0666);
    union Semun semun;

    if (semid == -1 || shmid == -1)
    {
        printf("\nShared memory or semaphore creation error\n");
        exit(0);
    }
    if (semctl(semid, 0, SETVAL, semun) == -1)
    {
        printf("error in initing semaphore set");
        exit(-1);
    }
    server(semid);
}