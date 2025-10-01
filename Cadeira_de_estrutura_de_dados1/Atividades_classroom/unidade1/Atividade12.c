#include <stdio.h>
#include <String.h>

int main() {
    char nome_jogador[51];

    printf("Insira um nome:\n");
    scanf("%[^\n]s", nome_jogador);

    if(strlen(nome_jogador) <= 15){
        printf("Nome valido! Bem-vindo ao jogo %s", nome_jogador);
    }else{
        printf("Nome muito longo! Por favor, escolha um nome com ate 15 caracteres.");
    }

    return 0;
}
