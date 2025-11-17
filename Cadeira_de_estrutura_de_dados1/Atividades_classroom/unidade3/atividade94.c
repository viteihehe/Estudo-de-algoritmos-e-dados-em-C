#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome [50];
} Mercenario;

typedef struct No {
    Mercenario dado;
    struct No * prox;
} No;

typedef struct {
    No * inicio;
} Lista;

void ler(Mercenario * m) {
    printf("Insira o id:\n");
    scanf("%d", &m->id);
    printf("Insira o nome:\n");
    scanf(" %[^\n]s", m->nome);
}

void contratar_mercenario(Lista * lista, Mercenario m) {
    No * novo = (No *)malloc(sizeof(No));
    novo->dado = m;
    novo->prox = NULL;
    if(lista->inicio == NULL) {
        lista->inicio = novo;
    }else {
        No * temp = lista->inicio;
        while(temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novo;
    }
}

void exibir_companhia(Lista lista) {
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

void demitir_todos_mercenarios(Lista * lista) {
    if(lista->inicio == NULL) {
        printf("A lista esta vazia!\n");
    }else {
        No * temp;
        while(lista->inicio != NULL) {
            temp = lista->inicio;
            lista->inicio = temp->prox;
            free(temp);
        }
    }
}

int tamanho(Lista lista) {
    if(lista.inicio == NULL) {
        return 0;
    }else {
        No * temp;
        int cont = 0;
        for(temp = lista.inicio; temp != NULL; temp = temp->prox) {
            cont++;
        }
        return cont;
    }
}

void menu() {
    printf("===========================\n");
    printf("1. Contratar mercenario\n");
    printf("2. Exibir companhia'\n");
    printf("3. Declarar falencia\n");
    printf("4. Tamanho atual da guida\n");
    printf("5. Sair\n");
    printf("===========================\n");
}

int main() {
    Lista lista;
    lista.inicio = NULL;
    int op = 1;
    Mercenario m;

    while(op) {
        menu();
        scanf("%d", &op);

        switch (op) {
            case 1:
                ler(&m);
                contratar_mercenario(&lista, m);
                break;
            case 2:
                exibir_companhia(lista);
                break;
            case 3:
                demitir_todos_mercenarios(&lista);
                exibir_companhia(lista);
                break;
            case 4:
                int temp = tamanho(lista);
                printf("Tamanho da guilda: %d\n", temp);
                break;
            case 5:
                op = 0;
                break;
            default:
                op = 1;
                break;
        }
    }


    return 0;
}