#include <stdio.h>
#include <stdlib.h>

int fibonacci_rec(int n) {
    if (n < 2)
        return 1;
    else
        return (fibonacci_rec(n - 1) + fibonacci_rec(n - 2));
}

int fibonacci_iter(int n) {
    int *f_arr = (int *)malloc(sizeof(int) * (n + 1));
    f_arr[0] = 1;
    f_arr[1] = 1;

    for (int i = 2; i <= n; i++) {
        f_arr[i] = f_arr[i - 1] + f_arr[i - 2];
    }

    int result = f_arr[n];
    free(f_arr);
    
    return f_arr[n];
}

int main() {
    int result_rec = fibonacci_rec(10);
    int result_iter = fibonacci_iter(10);

    printf("fibonacci result :: iter = %d , recur = %d\n", result_iter, result_rec);

    return 0;
}