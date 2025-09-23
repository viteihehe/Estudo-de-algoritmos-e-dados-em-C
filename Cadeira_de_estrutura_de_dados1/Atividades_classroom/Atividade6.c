#include <stdio.h>

int main() {
  int plataformas[] = {10,20,5,15,30}, altura = 0, i;
  int *ponteiro_plataformas = plataformas;

  for(i = 0; i < 5; i++){
    altura += *(ponteiro_plataformas + i);
  }

  printf(" Altura total do salto: %d metros!", altura);

    return 0;
}