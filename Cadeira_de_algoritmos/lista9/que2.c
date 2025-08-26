#include <stdio.h>
#include <locale.h>

int main(){
  setlocale(LC_ALL, "portuguese");
  char nome[100];
  int cont = 0;

  printf("Insira seu nome:\n");
  gets(nome);

  for(int i = 0; i < 100; i++){
    if(nome[i] != '\0'){
        cont++;
    }else{
        break;
    }
  }

  printf("Tamanho do array: %d\n", cont);

    return 0;
}