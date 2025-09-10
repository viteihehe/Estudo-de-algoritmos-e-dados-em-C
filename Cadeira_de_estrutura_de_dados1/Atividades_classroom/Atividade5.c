#include <stdio.h>

int main(){
 int pontuacao= 0;
 int *ppontuacao;
 ppontuacao= &pontuacao;

    printf("Pontuacao inicial: %d\n", *ppontuacao);

    for(int i = 0; i < 3; i++){
        *ppontuacao += 10;
    }

    printf("Pontuacao final apos coletar 3 moedas: %d\n", *ppontuacao);

    return 0;
}