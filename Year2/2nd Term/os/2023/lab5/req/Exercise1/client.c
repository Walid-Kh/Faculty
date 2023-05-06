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

struct msgbuffer
{
    long mtype;
    char message[256];
};

void client(int up, int down)
{
    while (1)
    {
        struct msgbuffer msbuf;
        msbuf.mtype = getpid() % 10000;
        scanf("%s", msbuf.message);
        printf("\nClient sent : %s", msbuf.message);
        if (msgsnd(up, &msbuf, sizeof(msbuf.message), !IPC_NOWAIT) == -1)
        {
            printf("\nerror in client sending");
            exit(-1);
        }
        if (msgrcv(down, &msbuf, sizeof(msbuf.message), msbuf.mtype, !IPC_NOWAIT) == -1)
        {
            printf("\nerror in client receiving");
            exit(-1);
        }
        printf("\nClient received : %s\n", msbuf.message);
    }
}
void handler(int signum)
{
    exit(0);
}
int main(int argc, char **argv)
{
    signal(SIGINT, handler);
    key_t k_down = ftok("downkey", 65);
    key_t k_up = ftok("upkey", 66);
    int downQ = msgget(k_down, 0666 | IPC_CREAT);
    int upQ = msgget(k_up, 0666 | IPC_CREAT);
    if (downQ == -1 || upQ == -1)
    {
        printf("\nerror in creating msg queues");
        exit(-1);
    }
    client(upQ, downQ);
}