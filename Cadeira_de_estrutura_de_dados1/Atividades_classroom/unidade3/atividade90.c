#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome [100];
} Ward;

typedef struct No {
    Ward dado;
    struct No * prox_no;
} No;

typedef struct {
    No * inicio;
} Lista;

void ler(Ward * w) {
    printf("Insira id:\n");
    scanf("%d", &w->id);
    printf("Insira o nome:\n");
    scanf(" %[^\n]s", w->nome);
}

void inserir_ward(Lista * lista, Ward w) {
    No * novo = (No *)malloc(sizeof(No));
    novo->dado = w;
    novo->prox_no = NULL;
    if(lista->inicio == NULL) {
        lista->inicio = novo;
    }else {
        No * temp;
        for(temp = lista->inicio; temp->prox_no != NULL; temp = temp->prox_no);
        temp->prox_no = novo;
    }
}

void lancar_wards(Lista * lista, int id) {
    if(lista->inicio == NULL) {
        printf("A lista esta vazia!\n");
    }else if(lista->inicio->prox_no == NULL) {
        printf("Nao foi possivel apagar o proximo ward!\n");
    }else {
        No * temp;
        No * temp2;
        for(temp = lista->inicio; temp != NULL && temp->dado.id != id; temp = temp->prox_no);
        if(temp == NULL) {
            printf("Não foi possivel deletar o ward!\n");
        }else if (temp->prox_no == NULL) {
            printf("Não foi possivel deletar o ward!\n");
        }else {
            temp2 = temp->prox_no;
            temp->prox_no = temp2->prox_no;
            free(temp2);
        }
    }
}

void mostrar_lista(Lista lista) {
    if(lista.inicio == NULL) {
        printf("A lista esta vazia!\n");
    }else {
        No * temp = lista.inicio;
        while(temp != NULL) {
            printf("Nome: %s, ID: %d\n", temp->dado.nome, temp->dado.id);
            temp = temp->prox_no;
        }
    }
}

void menu() {
    printf("===========================\n");
    printf("1. Adicionar Ward\n");
    printf("2. Lancar 'Ward Shatter'\n");
    printf("3. Mostrar Wards Ativos\n");
    printf("4. Sair\n");
    printf("===========================\n");
}

int main() {
    Lista lista;
    lista.inicio = NULL;
    int op = 1;
    Ward w;

    while(op) {
        menu();
        scanf("%d", &op);

        switch (op) {
            case 1:
                ler(&w);
                inserir_ward(&lista, w);
                break;
            case 2:
                int id;
                printf("Insira o id:\n");
                scanf("%d", &id);
                lancar_wards(&lista, id);
                break;
            case 3:
                mostrar_lista(lista);
                break;
            case 4:
                op = 0;
                break;
            default:
                break;
        }
    }


    return 0;
}