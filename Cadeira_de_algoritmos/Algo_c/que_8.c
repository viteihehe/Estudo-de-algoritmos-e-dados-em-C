#include <stdio.h>
#include <locale.h>

int main(){
  setlocale(LC_ALL,"portuguese");
  float r,d;

    printf("Coloque a cotação do dolar:\n");
    scanf("%f", &d);
    printf("Insira o valor em real para ser convertido:\n");
    scanf("%f", &r);

    r = r/d;

    printf("Valor em dolar convertido: %.2f$\n", r);

    return 0;
}