#include <stdio.h>
#include<string.h>

struct Jogador
{
    char nome[50];
    int vidas;
    int pontuacao;
};

int main() {
    char nome_digitado[50];
    struct Jogador player1 = {"",3,0};

        printf("Insira seu nome:\n");
            scanf("%[^\n]s", nome_digitado);

            strcpy(player1.nome, nome_digitado);

            printf("Personagem criado! Bem-vindo, %s! Vidas: %d, Pontuação: %d", player1.nome, player1.vidas, player1.pontuacao);



    return 0;
}