#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int ID;
    char nome [50];
} Movimento;

typedef struct No {
    Movimento dado;
    struct No * prox_no;
} No;

typedef struct {
    No * inicio;
} Lista;

void menu() {
    printf("==============================\n");
    printf("1:Inserir novo movimento no inicio do combo:\n");
    printf("2:Sair\n");
    printf("=================================\n");
}

void add(Lista* lista, Movimento mov) {
    No* novo = (No *)malloc(sizeof(No));
    novo->dado = mov;
    novo->prox_no = lista->inicio;
    lista->inicio = novo;
}

void ler(Movimento * novo_movimento) {
    printf("Nome:\n");
    scanf(" %[^\n]s", novo_movimento->nome);
    printf("ID:\n");
    scanf("%d", &novo_movimento->ID);
}

int main() {
    Lista lista;
    lista.inicio = NULL;
    int op = 0;
    while(op != 2) {
        menu();
        scanf("%d", &op);
        if(op == 1) {
            Movimento m;
            ler(&m);
            add(&lista, m);
        }
    }
    printf("Encerrando o programa\n");

    return 0;
}