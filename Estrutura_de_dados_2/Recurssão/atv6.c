//Calculo de potência por multiplicação
#include <stdio.h>


int pow_aux(int k, int n, int resultado) {
    if(n == 0) {
        return resultado;
    }

    return pow_aux(k, n-1, resultado*k);

}

int pow_me(int k, int n) {
    return pow_aux(k, n, 1);
}

int main() {

    int r = pow_me(2, 10);
    printf("%d \n", r);


    return 0;
}