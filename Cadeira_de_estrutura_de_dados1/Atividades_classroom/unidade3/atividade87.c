#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[50];
} Jogador;

typedef struct No {
    Jogador dado;
    struct No * prox_no;
} No;

typedef struct {
    No * inicio;
} Lista;

void ler(Jogador * jogador) {
    printf("Insira o nome:\n");
    scanf(" %[^\n]s", jogador->nome);
    printf("Insira o id:\n");
    scanf("%d", &jogador->id);
}

void inserir_final(Lista * lista, Jogador jogador) {
    No * novo = (No *)malloc(sizeof(No));
    novo->dado = jogador;
    novo->prox_no = NULL;
    if(lista->inicio == NULL) {
        lista->inicio = novo;
    }else {
        No * temp;
        for(temp = lista->inicio; temp->prox_no != NULL; temp = temp->prox_no);
        temp->prox_no = novo;
    }
}

void motrar_lista(Lista lista) {
    if(lista.inicio == NULL) {
        printf("A lista está vazia!\n");
    }else {
        No * temp = lista.inicio;
        while(temp != NULL) {
            printf("%s, ID: %d\n", temp->dado.nome, temp->dado.id);
            temp = temp->prox_no;
        }
    }
}

void deletar_primeiro(Lista * lista) {
    if(lista->inicio == NULL) {
        printf("Nao ha jogadores na fila!\n");
    }else {
        No * temp = lista->inicio;
        lista->inicio = lista->inicio->prox_no;
        free(temp);
    }
}

void menu() {
    printf("======================================\n");
    printf("1 - Adicionar jogador ao fim da fila\n");
    printf("2 - Iniciar partida\n");
    printf("3 - Mostrar fila de espera\n");
    printf("4 - Sair\n");
    printf("========================================\n");
}

int main() {
   Lista lista;
   lista.inicio = NULL;
   Jogador j;
   int op = 0;
   while(op != 4) {
        menu();
        scanf("%d", &op);

        switch (op) {
            
            case 1:
                ler(&j);
                inserir_final(&lista, j);
                break;
            
            case 2:
                deletar_primeiro(&lista);
                break;
            
            case 3:
                motrar_lista(lista);
                break;

            case 4:
                op == 4;
                break;

            default:
                break;
        }
   }
}