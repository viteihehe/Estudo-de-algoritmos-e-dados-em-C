//MDC
#include <stdio.h>

int aux(int x, int y) {
    if(y == 0) {
        return x;
    }

    return aux(y, x%y);
}

int MDC(int x, int y) {
    return aux(x, y);
}

int main() {


    int x = MDC(4, 12);
    printf("%d ", x);

    return 0;
}