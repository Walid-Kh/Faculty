#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool checkReversed(char *str1, char *str2)
{
    if ((sizeof(str1) - sizeof(str2)) != 0)
    {
        return false;
    }
    else
    {
        int n = strlen(str1);
        int i0 = 0;
        int i1 = n - 1;
        while (i0 <= i1)
        {
            if (str1[i0] != str2[i1])
                return false;
            i0++;
            i1--;
        }
        return true;
    }
}
int main(int argc, char **argv)
{
    char *str1 = argv[1];
    char *str2 = argv[2];
    if (checkReversed(str1, str2))
    {
        printf("Strings are reversed");
        exit(55);
    }
    else
    {
        printf("NO");
        exit(55);
    }
    return 0;
}
