#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){

float x, y;

x = atof(argv[1]);
y=x*x;

    printf("%s do kwadratu to %f\n", argv[1], y);

return 0;
}