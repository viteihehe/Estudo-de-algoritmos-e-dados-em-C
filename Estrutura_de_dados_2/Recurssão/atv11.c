//Multiplicação por soma sucessiva
#include <stdio.h>


int mult_aux(int x, int y, int acc) {
    if(x == 0 || y == 0) {
        return acc;
    }
    return mult_aux(x-1, y, acc+y);
}

int mult(int x, int y) {
    return mult_aux(x, y, 0);
}


int main() {

    int x = mult(4,9);

    printf("%d \n", x);


    return 0;
}