#include <stdio.h>
#include <string.h>

int main() {
    char palavra_secreta[] = {"LUX"};
    char tentativa_jogador[50];

    printf("Uma voz ancestral ecoa... Diga a palavra e passe:\n");
    scanf("%[^\n]s", tentativa_jogador);

    if(strcmp(tentativa_jogador, palavra_secreta) == 0){
        printf("A porta magica se abre!\n");
    }else{
        printf(" Nada acontece... Parece que a palavra esta incorreta.\n");
    }






    return 0;
}