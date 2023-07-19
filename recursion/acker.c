#include <stdio.h>

int acker_rec(int m, int n) {
    if (m == 0) return n+1;
    if (n == 0) return acker_rec(m-1 , 1);
    return acker_rec(m-1 , acker_rec(m , n-1));
}

int main() {
    int result = acker_rec(4, 1);
    printf("%d\n", result);

    return 0;
}