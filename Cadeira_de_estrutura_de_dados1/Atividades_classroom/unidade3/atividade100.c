#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int custo_mana;
    char nome [100];
} Feitico;

typedef struct No {
    Feitico dado;
    struct No * prox;
} No;

typedef struct {
    No * topo;
} Pilha;

void ler(Feitico * f) {
    printf("Insira o nome:\n");
    scanf(" %[^\n]s", f->nome);
    printf("Insira o custo de mana:\n");
    scanf("%d", &f->custo_mana);
}

void push(Pilha * pilha, Feitico f) {
    No * novo = (No *)malloc(sizeof(No));
    novo->dado = f;
    if(pilha->topo == NULL) {
        pilha->topo = novo;
        novo->prox = NULL;
    }else {
        novo->prox = pilha->topo;
        pilha->topo = novo;
    }
}

int main() {
    Pilha pilha;
    pilha.topo = NULL;
    Feitico f;
    int op = 1;

    while(op) {
        printf("1: Adicionar um novo feitico a pilha de comandos\n");
        printf("2: Finalizar a sequencia de comando e sair\n");
        scanf("%d", &op);

        switch (op) {
            case 1:
                ler(&f);
                push(&pilha, f);
                break;
            case 2:
                op = 0;
                break;
            default:
                op = 1;
                break;
        }
    }

    return 0;
}