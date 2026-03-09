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

void mostrar(Fila f) {
    if(f.inicio == NULL) {
        printf("A fila esta vazia\n");
    }else {
        No * aux;
        for(aux = f.inicio; aux != NULL; aux = aux->prox) {
        printf("Nickname: %s, ID: %d\n", aux->dado.nickname, aux->dado.id);
    }
    }
}

Jogador remover(Fila *f) {
    if(f->inicio == NULL) {
        printf("Erro ao remover uma fila vazia!\n");
        Jogador j = {-1, ""};
        return j;
    }else if(f->inicio->prox == NULL){
        No * temp;
        temp = f->inicio;
        Jogador j = temp->dado;
        f->inicio = NULL;
        f->fim = NULL;
        free(temp);
        return j;
    }else {
        No * temp;
        temp = f->inicio;
        Jogador j = temp->dado; 
        f->inicio = temp->prox;
        free(temp);
        return j;
    }
}

void menu() {
    printf("==========================================\n");
    printf("1: Inserir item na fila\n");
    printf("2: Mostrar fila\n");
    printf("3: Remover da fila\n");
    printf("4: Sair\n");
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
                mostrar(fila);
                break;
            case 3:
                j = remover(&fila);
                if(j.id != -1) {
                    printf("O jogador %s(ID: %d) foi removido da fila e entrou em uma partida\n", j.nickname, j.id);
                }
                break;
            case 4:
                op = 0;
                break;

            default:
                op = 1;
                break;
        }
    }


    return 0;
}