#include <stdio.h>
#include <locale.h>

float areare(float a, float b, float c);

int main(){
  setlocale(LC_ALL, "portuguese");
  float a, b, c, r;

  printf("Insira o comprimento:\n");
  scanf("%f", &a);
  printf("Insira a largura:\n");
  scanf("%f", &b);
  printf("Insria a altura:\n");
  scanf("%f", &c);

  r = areare(a, b, c);

  printf("Área calculada do retângulo: %.2f\n", r);


    return 0;
}

float areare(float a, float b, float c){
  return(a*b*c);
}
