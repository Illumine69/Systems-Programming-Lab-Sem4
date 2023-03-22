#include <stdio.h>
#include <stdlib.h>
int main (){
    int n, x, sum;
    n = sum = 0;
    printf("Keep on entering non-negative integers. Enter a negative integer to end.\n");
    while (1) {
        printf("Next number: "); scanf("%d", &x);
        if (x < 0) break;
        ++n; sum += x;
    }
    printf("Average of the numbers entered is %lf\n", (double)sum / (double)n);
    exit(0);
}