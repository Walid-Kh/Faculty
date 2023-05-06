#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <unistd.h>

union Semun
{
    int val;               /* value for SETVAL */
    struct semid_ds *buf;  /* buffer for IPC_STAT & IPC_SET */
    unsigned short int *array;         /* array for GETALL & SETALL */
    struct seminfo *__buf; /* buffer for IPC_INFO */
    void *__pad;
};

void down(int sem) //wait
{
    struct sembuf p_op;

    p_op.sem_num = 0;
    p_op.sem_op = -1;
    p_op.sem_flg = !IPC_NOWAIT;

    if (semop(sem, &p_op, 1) == -1)
    {
        perror("Error in down()");
        exit(-1);
    }
}

void up(int sem) //signal
{
    struct sembuf v_op;

    v_op.sem_num = 0;
    v_op.sem_op = 1;
    v_op.sem_flg = !IPC_NOWAIT;

    if (semop(sem, &v_op, 1) == -1)
    {
        perror("Error in up()");
        exit(-1);
    }
}


int main() {
    key_t shm_key = 1234;
    key_t sem_key = 5678;

    int shmid = shmget(shm_key, 256, IPC_CREAT | 0666);

    if (shmid == -1)
    {
        perror("Error in create");
        exit(-1);
    }
    else
        printf("\nShared memory ID = %d\n", shmid);

    char *shmaddr = shmat(shmid, (void *)0, 0);

    int sem_id = semget(sem_key, 1, 0666 | IPC_CREAT);

    if (sem_id == -1 )
    {
        perror("Error in create sem");
        exit(-1);
    }

    union Semun sem_union;
    sem_union.val = 0; /* initial value of the semaphore, Binary semaphore */
    if (semctl(sem_id, 0, SETVAL, sem_union) == -1)
    {
        perror("Error in semctl");
        exit(-1);
    }

    while (1) {
        char str[256];
        printf("Please enter the message to be converted: ");
        fgets(str, 256, stdin);
        strcpy(shmaddr, str);
        up(sem_id);
        down(sem_id);
        printf("Processed message: %s\n", shmaddr);
    }

    shmdt(shmaddr);
    return 0;
}