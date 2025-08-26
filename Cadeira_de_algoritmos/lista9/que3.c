#include <stdio.h>
#include <locale.h>

int main(){
  setlocale(LC_ALL, "portuguese");
  int v[5];
  int soma = 0;

  for(int i = 0; i < 5; i++){
    printf("Insira o %d valor:\n", i+1);
    scanf("%d", &v[i]);

    soma += v[i];
  }
  printf("Soma dos valores: %d\n", soma);

    return 0;
}