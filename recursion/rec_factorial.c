#include <stdio.h>

int rec_factorial(int n) {
    //if (n == 2)
    //    return 2;
    if (n == 1) // base condition : 내가 직접 해결할 수  있는 문제크기
        return 1;
    else //이보다 작은 문제로 분할(해결방법이 같다)
        return n * rec_factorial(n - 1);
}

int main() {
    int result = rec_factorial(10);

    printf("result : %d\n", result);
    return 0;
}