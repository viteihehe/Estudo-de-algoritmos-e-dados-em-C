#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome [100];
    int nivel;
} Membro;

typedef struct No {
    Membro dado;
    struct No * prox;
} No;

typedef struct {
    No * inicio;
} Lista;

void inserir_final(Lista * lista, Membro m) {
    No * novo = (No *)malloc(sizeof(No));
    novo->dado = m;
    novo->prox = NULL;
    if(lista->inicio == NULL) {
        lista->inicio = novo;
    }else {
        No * temp;
        for(temp = lista->inicio; temp->prox != NULL; temp = temp->prox);
        temp->prox = novo;
    }
}

Lista carregar_guilda() {
    FILE* file = fopen("./guild_roster.bin", "rb");
    Lista lista;
    Membro m;
    lista.inicio = NULL;
    while(fread(&m, sizeof(Membro), 1, file) != 0) {
        inserir_final(&lista, m);
    }
    fclose(file);
    return lista;
}

void mostrar_lista(Lista lista) {
    if(lista.inicio == NULL) {
        printf("A lista esta vazia!\n");
    }else {
        No * temp;
        for(temp = lista.inicio; temp != NULL; temp = temp->prox) {
            printf("Nome: %s, Nivel: %d, ID: %d\n", temp->dado.nome, temp->dado.nivel, temp->dado.id);
        }
    }
}

int main() {
    Lista lista;
    lista.inicio = NULL;

    lista = carregar_guilda();
    mostrar_lista(lista);

    return 0;
}