#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome [50];
} Item;

typedef struct No {
    Item dado;
    struct No * prox_no;
} No;

typedef struct {
    No * inicio;
} Lista;

void ler(Item * item) {
    printf("Insira o nome do item:\n");
    scanf(" %[^\n]s", item->nome);
    printf("Insira o id:\n");
    scanf("%d", &item->id);
}

void inserir_inicio(Lista * lista, Item item) {
    No * novo = (No *)malloc(sizeof(No));
    novo->dado = item;
    novo->prox_no = lista->inicio;
    lista->inicio = novo;
}

void inserir_final(Lista * lista, Item item) {
    No * novo = (No *)malloc(sizeof(No));
    novo->dado = item;
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
        printf("A lista está vazia!\n");
    }else {
        while(temp != NULL) {
            printf("%s ID: %d\n", temp->dado.nome, temp->dado.id);
            temp = temp->prox_no;
        }
    }
}

No * inserir_apos(Lista * lista, Item item, int id) {
    No * novo = (No *)malloc(sizeof(No));
    novo->dado = item;
    No * temp;
    for(temp = lista->inicio; temp != NULL && temp->dado.id != id; temp = temp->prox_no);
    if(temp == NULL) {
        return temp;
    }else {
        novo->prox_no = temp->prox_no;
        temp->prox_no = novo;
        return temp;
    }
    
}
/*1 - Inserir item no início (para itens comuns).
2 - Inserir item no fim (para itens comuns).
3 - Inserir catalisador após um fragmento (o foco da tarefa).
4 - Mostrar inventário.
5 - Sair.*/

void menu() {
    printf("===========================================\n");
    printf("1 - Inserir item no inicio\n");
    printf("2 - Inserir item no fim\n");
    printf("3 -Inserir catalisador após um fragmento\n");
    printf("4 - Mostrar inventário\n");
    printf("5 - Sair\n");
    printf("===========================================\n");
}

int main() {
    Lista lista;
    lista.inicio = NULL;
    int op = 0;
    Item i;
    while(op != 5) {
        menu();
        scanf("%d", &op);
        switch (op) {
            case 1:
                ler(&i);
                inserir_inicio(&lista, i);
                break;
            case 2:
                ler(&i);
                inserir_final(&lista, i);
                break;
            case 3:
                int id;
                printf("Insira o id do item:\n");
                scanf("%d", &id);
                ler(&i);
                No * pi = inserir_apos(&lista, i, id);
                if(pi ==  NULL) {
                    printf("Nao foi possivel inserir o estudadente!\n");
                }
                break;
            case 4:
                mostrar_lista(lista);
                break;
            case 5:
                op = 5;
                break;
            default:
                break;
        }
    }


    return 0;
}