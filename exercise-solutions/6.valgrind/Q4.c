#include <stdio.h>
#include <stdlib.h>

int main(){
    int **p;
    p = (int **)malloc(3 * sizeof(int *));
    p[0] = p[1] = (int *)malloc(10 * sizeof(int));
    p[1] = p[2] = (int *)malloc(11 * sizeof(int));
    p[2] = p[0] = (int *)malloc(12 * sizeof(int));
    p = (int **)malloc(3 * sizeof(int *));
    *p = (int *)malloc(5 * sizeof(int));
    *(p+1) = (int *)malloc(6 * sizeof(int));
    *(p+2) = (int *)malloc(7 * sizeof(int));
    p[0] = p[1] = p[2] = NULL;
}