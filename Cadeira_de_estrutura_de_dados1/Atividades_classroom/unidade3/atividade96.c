#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome [50];
} Monstro;

typedef struct No {
    Monstro dado;
    struct No * prox;
} No;

typedef struct {
    No * inicio;
} Lista;

void ler(Monstro * m) {
    printf("Insira o id:\n");
    scanf("%d", &m->id);
    printf("Insira o nome:\n");
    scanf(" %[^\n]s", m->nome);
}

void adicionarMonstro(Lista * lista, Monstro m) {
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

void ordenarBestiario(Lista * lista) {
    if(lista->inicio == NULL) {
        return;
    }else {
        No * pi; 
        No * pj; 
        No * pfim = NULL;
        for(pi = lista->inicio; pi->prox != NULL; pi = pi->prox) {
            for(pj = lista->inicio; pj->prox != pfim; pj = pj->prox) {
                if(pj->dado.id > pj->prox->dado.id) {
                    Monstro temp = pj->prox->dado;
                    pj->prox->dado = pj->dado;
                    pj->dado = temp;
                }
            }
            pfim = pj;
        }
    }
}

void mostrarBestirario(Lista lista) {
    if(lista.inicio == NULL) {
        printf("A lista esta vazia!\n");
    }else {
        No * temp = lista.inicio;
        while(temp != NULL) {
            printf("ID: %d, Nome: %s\n", temp->dado.id, temp->dado.nome);
            temp = temp->prox;
        }
    }
}

void menu() {
    printf("===========================\n");
    printf("1. Adicionar mosntro\n");
    printf("2. Mostrar bestiario'\n");
    printf("3. ordenar bestiario\n");
    printf("4. Sair\n");
    printf("===========================\n");
}

int main() {
    Lista lista;
    lista.inicio = NULL;
    int op = 1;
    Monstro m;

    while(op) {
        menu();
        scanf("%d", &op);
        
        switch (op) {
            case 1:
                ler(&m);
                adicionarMonstro(&lista, m);
                mostrarBestirario(lista);
                break;
            case 2:
                mostrarBestirario(lista);
                break;
            case 3:
                ordenarBestiario(&lista);
                mostrarBestirario(lista);
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