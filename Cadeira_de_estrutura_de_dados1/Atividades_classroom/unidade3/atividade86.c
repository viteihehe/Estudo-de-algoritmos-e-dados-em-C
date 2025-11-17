#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome [50];
} Heroi;

typedef struct No {
    Heroi dado;
    struct No * prox_no;
} No;

typedef struct {
    No * inicio;
} Lista;

void ler(Heroi * heroi) {
    printf("Insira o nome:\n");
    scanf(" %[^\n]s", heroi->nome);
    printf("Insira o id:\n");
    scanf("%d", &heroi->id);
}

void inserir_final(Lista * lista, Heroi heroi) {
    No * novo = (No *)malloc(sizeof(No));
    novo->dado = heroi;
    novo->prox_no = NULL;
    if(lista->inicio == NULL) {
        lista->inicio = novo;
    }else {
        No * temp;
        for(temp = lista->inicio; temp->prox_no != NULL; temp = temp->prox_no);
        temp->prox_no = novo;
    }
}

void mostrar_lista(Lista lista) {
    No * temp = lista.inicio;
    if(temp == NULL) {
        printf("Lista vazia!\n");
    }else {
        while(temp != NULL) {
            printf("%s, ID: %d\n", temp->dado.nome, temp->dado.id);
            temp = temp->prox_no;
        }
    }
}

No * inserir_antes(Lista * lista, Heroi h, int id) {
    No * novo = (No *)malloc(sizeof(No));
    novo->dado = h;
    if(lista->inicio == NULL) {
        return NULL;
    }else if(lista->inicio->dado.id == id) {
        novo->prox_no = lista->inicio;
        lista->inicio = novo;
    }else {
        No * temp;
        for(temp = lista->inicio; temp->prox_no != NULL && temp->prox_no->dado.id != id; temp = temp->prox_no);
        if(temp == NULL) {
            return temp;
        }else {
            novo->prox_no = temp->prox_no;
            temp->prox_no = novo;
            return temp;
        }
    }
}

void menu() {
    printf("======================================\n");
    printf("1 - Adicionar Heroi no Fim da Formacao\n");
    printf("2 - Adicionar Guarda-Costas\n");
    printf("3 - Mostrar Formacao\n");
    printf("4 - Sair\n");
    printf("========================================\n");
}

int main() {
    Lista lista;
    lista.inicio = NULL;
    Heroi h;
    int op = 0;

    while(op != 4) {
        menu();
        scanf("%d", &op);
        switch (op) {
            case 1:
                ler(&h);
                inserir_final(&lista, h);
                break;
            case 2:
                int id;
                printf("Insira o id:\n");
                scanf("%d", &id);
                ler(&h);
                No * temp = inserir_antes(&lista, h, id);
                if(temp == NULL) {
                    printf("Nao foi possivel inserir!\n");
                }
                break;
            case 3:
                mostrar_lista(lista);
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