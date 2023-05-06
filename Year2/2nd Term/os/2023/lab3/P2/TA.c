#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char *argv[])

{
    char *filePath = argv[1];
    int TaNum = atoi(argv[2]);
    int passGrade = atoi(argv[3]);

    FILE *fp;
    fp = fopen(filePath, "r");
    if (fp == NULL)
    {
        printf("it's not opening");
        return 1;
    }

    int numberOfStudent;
    fscanf(fp, "%d", &numberOfStudent);

    int midGrades[numberOfStudent];
    int finialGrades[numberOfStudent];
    for (int i = 0; i < numberOfStudent; i++)
    {
        int x, y;
        fscanf(fp, "%d %d", &x, &y);
        midGrades[i] = x;
        finialGrades[i] = y;
    }

    int studentsPerTa[TaNum];
    int TaStart[TaNum];
    int Tapid[TaNum];

    for (size_t i = 0; i < TaNum; i++)
    {
        studentsPerTa[i] = numberOfStudent / TaNum;
        TaStart[i] = i * studentsPerTa[i];
    }
    if (TaNum % numberOfStudent != 0)
        studentsPerTa[TaNum - 1] += numberOfStudent % TaNum;
    for (int i = 0; i < TaNum; i++)
    {
        int pid;
        pid = fork();
        if (pid == -1)
        {
            perror("error in forking");
        }
        else if (pid == 0)
        {
            // child
            int res = 0;
            for (int j = TaStart[i]; j < TaStart[i] + studentsPerTa[i]; j++)
                if (midGrades[j] + finialGrades[j] >= passGrade)
                    res++;
            exit(res);
        }
        else
        {
            Tapid[i] = pid;
        }
    }
    for (int i = 0; i < TaNum; i++)
    {
        int stat;
        waitpid(Tapid[i], &stat, 0);
        printf("%d ", WEXITSTATUS(stat));
    }

    /* for (int i = 0; i < TaNum; i++)
    {
        printf("%d %d\n", studentsPerTa[i], TaStart[i]);
    } */

    return 0;
}
