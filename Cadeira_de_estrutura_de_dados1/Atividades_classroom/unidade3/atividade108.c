#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nickname [50];
} Jogador;

typedef struct No {
    Jogador dado;
    struct No * prox;
} No;

typedef struct {
    No * inicio;
    No * fim;
} Fila;

void ler(Jogador * j) {
    printf("Insira o nome:\n");
    scanf(" %[^\n]s", j->nickname);
    printf("Insira o id:\n");
    scanf("%d", &j->id);
}

void inserir(Fila *f, Jogador j) {
    No * novo = (No *)malloc(sizeof(No));
    novo->dado = j;
    novo->prox = NULL;
    if(f->inicio == NULL) {
        f->inicio = novo;
        f->fim = novo;
    }else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

void menu() {
    printf("==========================================\n");
    printf("1: Inserir item na fila\n");
    printf("2: Sair\n");
    printf("==========================================\n");
}

int main() {
    Fila fila;
    fila.fim = NULL;
    fila.inicio = NULL;
    Jogador j;
    int op = 1;

    while(op) {
        menu();
        scanf("%d", &op);

        switch (op) {
            case 1:
                ler(&j);
                inserir(&fila, j);
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