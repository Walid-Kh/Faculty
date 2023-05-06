#include <ctype.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void down(int sem) // wait
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

void up(int sem) // signal
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

void conv(char *msg, int size)
{
    int i;
    for (i = 0; i < size; ++i)
        if (islower(msg[i]))
            msg[i] = toupper(msg[i]);
        else if (isupper(msg[i]))
            msg[i] = tolower(msg[i]);
}

int main()
{
    key_t shm_key = 1234;
    key_t sem_key = 5678;

    int shm_id = shmget(shm_key, 256, 0666);
    char *shm_ptr = (char *)shmat(shm_id, NULL, 0);

    int sem_id = semget(sem_key, 1, 0666);

    while (1)
    {
        down(sem_id);
        conv(shm_ptr, sizeof(shm_ptr));
        up(sem_id);
    }

    shmdt(shm_ptr);
    return 0;
}

// client -> get input 
// wake up server 
// down 



// server -> waken up 
// convert 
// wake up client 
// down 