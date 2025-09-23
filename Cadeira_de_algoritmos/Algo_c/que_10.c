#include <stdio.h>

int main(){
  float i, al, p;
   
  printf("Calculadora de IMC\n\n");
    printf("Insira o seu peso(kg):\n");
    scanf("%f", &p);
      printf("Insira sua altura(m):\n");
      scanf("%f", &al);

        i = p/(al*al);

        printf("IMC: %.2f\n", i);

    return 0;
}