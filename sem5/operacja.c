#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(int argc, char *argv[])
{
    if(strcmp(argv[1], "dodaj") == 0)
    {
        float a = atof(argv[2]);
        float b = atof(argv[3]);
        float c = a + b;
        printf("%f\n", c);
    }

    if(strcmp(argv[1], "mnoz") == 0)
    {
        float a = atof(argv[2]);
        float b = atof(argv[3]);
        float c = a * b;
        printf("%f\n", c);
    }
}