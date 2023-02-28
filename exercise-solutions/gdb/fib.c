#include <stdio.h>
#include <stdlib.h>

int Fib ( int n ){
    if (n < 0) {
        return -1;
    }
    if (n <= 1) {
        return n;
    }
    return Fib(n-1) + Fib(n-2);
}
