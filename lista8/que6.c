#include <stdio.h>
#include <locale.h>

#define PI 3.14

float area(float a);

int main(){
  setlocale(LC_ALL, "portuguese");
  float a, r;

  printf("Insira o raio:\n");
  scanf("%f", &a);

  r = area(a);

  printf("Área do circulo é: %.2f", r);
    return 0;
}

float area(float a){
    return((a*a)*PI);
}
