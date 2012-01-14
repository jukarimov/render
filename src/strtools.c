#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 300

int
readln(char line[])
{
        int c, i;
        for (i=0; (c=getchar()) != EOF && c != '\n'; ++i)
                line[i] = c;

        line[i] = 0;

        return c == '\n' ? i : -1;
}

int
split(char *line, char **array, int del)
{
        int ll = strlen(line);
        char col[MAX];
        int row = 0;
        int i = 0, j = 0, x = 0;

        while(line[i] != '\n' && i < ll) {
                if(line[i] == del) {
                        x = i;
                        i++;
                        col[j++] = '\0';
                        strcpy(array[row++],col);
                        j = 0;
                }
                col[j++] = line[i++];
        }
        if(x==0) {
                //puts("no delim were found");
                col[j] = '\0';
                strcpy(array[row],col);
                return row+1;
        }
        j=0;
        if(line[i] == '\n' || line[i] == '\0') {
                i = x+1;
                while(i <= ll)
                        col[j++] = line[i++];
                j--;
                if(col[j-1] == '\n')
                        col[j-1] = '\0';
                col[j] = '\0';
                strcpy(array[row++],col);
        }
        return row;
}

