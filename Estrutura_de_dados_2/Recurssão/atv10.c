//Contador de repetição
#include <stdio.h>

int contador_aux(int valor, int numero, int cont) {
    if(numero <= 9) {
        if(valor == numero) {
            cont++;
        }
        return cont;
    }
    (valor == (numero%10)) ? cont++ : 0;
    return contador_aux(valor, numero/10, cont);

}

int contador(int valor, int numero) {
    return contador_aux(valor, numero, 0);
}

int main() {

    int x = contador(2, 21121);
    printf("%d \n", x);

    return 0;
}