#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome [100];
} Membro;

typedef struct No {
    Membro dado;
    struct No * prox;
} No;

typedef struct {
    No * inicio;
} Lista;

void ler(Membro * m) {
    printf("Insira o nome:\n");
    scanf(" %[^\n]s", m->nome);
    printf("Insira o id:\n");
    scanf("%d", &m->id);
}

void inserir_fim(Lista *lista, Membro m) {
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

void mostrar_lista(Lista lista) {
    if(lista.inicio == NULL) {
        printf("A lista esta vazia!\n");
    }else {
        No * temp = lista.inicio;
        while(temp != NULL) {
            printf("Nome: %s, ID: %d\n", temp->dado.nome, temp->dado.id);
            temp = temp->prox;
        }
    }
}

No * pesquisar(Lista * lista, int id) {
    No * temp;
    for(temp = lista->inicio; temp != NULL && temp->dado.id != id; temp = temp->prox);
    return temp; 
}

void alterar_nome(Lista * lista, int id, char novo_nome [100]) {
    if(lista->inicio == NULL) {
        printf("A lista esta vazia!\n");
    }else{
        No * buscado = pesquisar(lista, id);
        if(buscado == NULL) {
            printf("ID nao encontrado!\n");
        }else {
            strcpy(buscado->dado.nome, novo_nome);
        }
    }
}

void menu() {
    printf("===========================\n");
    printf("1. Adicionar membro\n");
    printf("2. Alterar nome\n");
    printf("3. Mostrar membros\n");
    printf("4. Sair\n");
    printf("===========================\n");
}

int main() {
    Lista lista;
    lista.inicio = NULL;
    int op = 1;
    Membro m;

    while(op) {
        menu();
        scanf("%d", &op);

        switch (op) {
            case 1:
                ler(&m);
                inserir_fim(&lista, m);
                break;
            case 2:
                char nome [100];
                int id;
                printf("Insira o id:\n");
                scanf("%d", &id);
                printf("Insira o novo nome:\n");
                scanf(" %[^\n]s", nome);
                alterar_nome(&lista, id, nome);
                break;
            case 3:
                mostrar_lista(lista);
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