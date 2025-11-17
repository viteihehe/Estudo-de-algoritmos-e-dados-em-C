#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int matricula;
    char nome [50];
} Jogador;

typedef struct No {
    Jogador dado;
    struct No * prox_no;
} No;

typedef struct lista {
    No * inicio;
} Lista;

void ler(Jogador * j) {
    printf("Insira o nome:\n");
    scanf( " %[^\n]s", j->nome);
    printf("Insira o ID:\n");
    scanf("%d", &j->matricula);
}

void inserir_inicio(Lista * lista, Jogador jogador) {
    No * novo = (No *)malloc(sizeof(No));
    novo->dado = jogador;
    novo->prox_no = lista->inicio;
    lista->inicio = novo;
}

void inserir_final(Lista * lista, Jogador jogador) {
    No * novo = (No *)malloc(sizeof(No));
    novo->dado = jogador;
    novo->prox_no = NULL;
    if(lista->inicio == NULL) {
        novo->prox_no = lista->inicio;
        lista->inicio = novo;
    }else {
        No * temp = lista->inicio;
        while(temp->prox_no != NULL) {
            temp = temp->prox_no;
        }
        temp->prox_no = novo;
    }
}

void mostrar(Lista lista) {
    No * temp = (No *)malloc(sizeof(No));
    temp = lista.inicio;
    if(temp == NULL) {
        printf("Lista vazia!\n");
    }else {
        while(temp != NULL) {
        printf("Nome: %s ID: %d\n", temp->dado.nome, temp->dado.matricula);
        temp = temp->prox_no;
    }
    }
}

void menu() {
    printf("=======================\n");
    printf("1 - Adicionar jogador no inicio da fila\n");
    printf("2 - Adicionar jogador no final da fila\n");
    printf("3 - Mostrar fila\n");
    printf("4 - Sair\n");
    printf("=======================\n");
}

int main() {
    Lista lista;
    lista.inicio = NULL;
    int op = 0;

    while(op != 4) {
        menu();
        scanf("%d", &op);
        switch (op) {
            case 1:
                Jogador j;
                ler(&j);
                inserir_inicio(&lista, j);
                break;
            case 2:
                Jogador j1;
                ler(&j1);
                inserir_final(&lista, j1);
                break;
            case 3:
                mostrar(lista);
                break;
            case 4:
                op = 4;
                break;
            default:
                break;
        }
    }




    return 0;
}