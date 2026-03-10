//Fibonacci
#include <stdio.h>

int aux(int n, int a, int b) {
    if(n == 0) {
        return a;
    }
    if(n == 1) {
        return b;
    }

    return aux(n-1, b, a+b);

}

int fibo(int n) {
    return aux(n, 0, 1);
}

int main() {

    int x = fibo(5);

    printf("%d", x);

    return 0;
}