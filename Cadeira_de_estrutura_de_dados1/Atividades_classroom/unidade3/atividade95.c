#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char tipo [50];
} Inimigo;

typedef struct No {
    Inimigo dado;
    struct No * prox;
} No;

typedef struct {
    No * inicio;
} Lista;

void ler(Inimigo * i) {
    printf("Insira o id:\n");
    scanf("%d", &i->id);
    printf("Insira o tipo:\n");
    scanf(" %[^\n]s", i->tipo);
}

void inserir_fim(Lista * lista, Inimigo i) {
    No * novo = (No *)malloc(sizeof(No));
    novo->prox = NULL;
    novo->dado = i;
    if(lista->inicio == NULL) {
        lista->inicio = novo;
    }else {
        No * temp;
        for(temp = lista->inicio; temp->prox != NULL; temp = temp->prox);
        temp->prox = novo;
    }
}

Lista criar_lista(int n) {
    if(n <= 0) {
        printf("Impossivel criar lista!\n");
    }else {
        Lista lista;
        lista.inicio = NULL;
        Inimigo ini;
        for(int i = 0; i < n; i++) {
            ler(&ini);
            inserir_fim(&lista, ini);
        }
        return lista;
    }
}

void mostrar(Lista lista) {
    if(lista.inicio == NULL) {
        printf("A lista esta vazia!\n");
    }else {
        No * temp = lista.inicio;
        while(temp != NULL) {
            printf("Tipo: %s, ID: %d \n", temp->dado.tipo, temp->dado.id);
            temp = temp->prox;
        }
    }
}


int main() {
    Lista lista;
    int n;
    printf("Insira a quantidade de inimigos:\n");
    scanf("%d", &n);
    lista = criar_lista(n);
    mostrar(lista);


    return 0;
}