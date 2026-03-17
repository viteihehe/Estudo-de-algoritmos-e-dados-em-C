#include <stdio.h>
#include <stdlib.h>

int fibo_aux(int n, int a, int b) {
    if(n == 0) {
        return b;
    }
    fibo_aux(n-1, b, a+b);
}

int fibo(int n) {
    return fibo_aux(n, 0, 1);
}

int main(int argc, char *argv[]) {
    int x = atoi(argv[1]);

    printf("Fibonacci de %d = %d\n", x, fibo(x));



}