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
int downQ;
int upQ;
struct msgbuffer
{
    long mtype;
    char message[256];
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

void server(int up, int down)
{
    while (1)
    {
        struct msgbuffer msbuf;
        msbuf.mtype = 1;
        printf("hello");
        if (msgrcv(up, &msbuf, sizeof(msbuf.message), 0, !IPC_NOWAIT) == -1)
        {
            printf("\nerror in server sending");
            exit(-1);
        }
        conv(msbuf.message, strlen(msbuf.message));
        if (msgsnd(down, &msbuf, sizeof(msbuf.message), !IPC_NOWAIT) == -1)
        {
            printf("\nerror in server sending");
            exit(-1);
        }
    }
}
void sigint_handler(int sig)
{
    msgctl(downQ, IPC_RMID, (struct msqid_ds *)0);
    msgctl(upQ, IPC_RMID, (struct msqid_ds *)0);
    exit(0);
}

int main(int argc, char **argv)
{
    signal(SIGINT, sigint_handler);
    key_t k_down = ftok("downkey", 65);
    key_t k_up = ftok("upkey", 66);
    downQ = msgget(k_down, 0666 | IPC_CREAT);
    upQ = msgget(k_up, 0666 | IPC_CREAT);
    if (downQ == -1 || upQ == -1)
    {
        printf("\nerror in creating msg queues");
        exit(-1);
    }
    server(upQ, downQ);
}
