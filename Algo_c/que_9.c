#include <stdio.h>

int main(){
  float a, l, c, v;
    
  printf("Calculador de volume retangular:\n");
    printf("Insira o comprimento:\n");
    scanf("%f", &c);
    printf("Insira a largura:\n");
    scanf("%f", &l);
    printf("Insira a altura:\n");
    scanf("%f", &a);

    v = c*l*a;

        printf("Volume do retangulo: %.2f\n", v);

    return 0;
}
