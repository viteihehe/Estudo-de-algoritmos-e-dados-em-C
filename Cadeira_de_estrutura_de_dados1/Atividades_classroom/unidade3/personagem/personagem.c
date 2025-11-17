#include "personagem.h"
#include <stdio.h>
#include <stdlib.h>

struct personagem {
    char nome [50];
    char classe [50];
    int nivel;
    int hp;
};

Personagem* cria_party(int num_membros) {
    Personagem* party = (Personagem *)malloc(num_membros*sizeof(Personagem));
    return party;
}

void registra_membros(Personagem* party, int num_membros) {
    for(int i = 0; i < num_membros; i++) {
        printf("Insira o nome do personagem %d:\n", i+1);
        scanf(" %[^\n]s", party[i].nome);
        printf("Insira a classe:\n");
        scanf(" %[^\n]s", party[i].classe);
        printf("Insira o hp:\n");
        scanf("%d", &party[i].hp);
        printf("Insira o nivel:\n");
        scanf("%d", &party[i].nivel);
    }
} 

void exibe_relatorio(const Personagem* party, int num_membros) {
    for(int i = 0; i < num_membros; i++) {
        printf("Nome: %s Classe: %s\nNivel: %d HP: %d\n", party[i].nome, party[i].classe, party[i].nivel, party[i].hp);
    }
}
void libera_party(Personagem* party) {
    free(party);
}