#include "math.h"

long factorial(int n) {
    long f = 1;
    for(int i = 1; i<=n; i++) {
        f = f * i;
    }
    return f;
}

long factorial2(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial2(n - 1);
}

