#include "heroi.h"
#include <stdlib.h>
#include <stdio.h>

struct heroi
{
    char nome [50];
    int hp;
    int ataque;
};

Heroi* criar(int n) {
    Heroi * herois = (Heroi *)malloc(n*sizeof(Heroi));
    return herois;
}

void ler(int n, Heroi * h) {
    for(int i = 0; i < n; i++) {
        printf("Insira o nome do heroi %d:\n", i+1);
        scanf(" %[^\n]s", h[i].nome);
        printf("Insira o hp:\n");
        scanf("%d", &h[i].hp);
        printf("Insira o ataque:\n");
        scanf("%d", &h[i].ataque);
    }
}

void imprimir(int n, Heroi* h) {
    for(int i = 0; i < n; i++) {
        printf("Nome: %s\n", h[i].nome);
        printf("HP: %d Ataque: %d\n", h[i].hp, h[i].ataque);
    }
}