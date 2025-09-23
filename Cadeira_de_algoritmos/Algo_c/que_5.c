#include <stdio.h>

int main(){
    float a,b;

    printf("Insira o primeiro valor:\n");
    scanf("%f", &a);
    printf("Insira o segundo valor:\n");
    scanf("%f", &b);
    printf("Dobro do primeiro: %.2f, Triplo do segundo: %.2f", a*2, b*3);


    return 0;
}