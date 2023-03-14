#include <stdio.h>
#include <math.h>

int spd ( int n ){
    int d, s;
    s = sqrt(n);
    for (d = 2; d < s; ++d) {
        if (n % d == 0) return d;
    }
    return 0;
}
int lpd ( int n ){
    int d;
    for (d = n / 2; d > 1; --d) {
        if (n % d == 0) return d;
    }
    return 0;
}
int main (){
    int n, N = 1e5;
    for (n=2; n<=N; ++n) {
        spd(n);
        lpd(n);
    }
}