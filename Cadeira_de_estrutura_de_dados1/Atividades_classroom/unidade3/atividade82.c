#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int ID;
    char nome [50];
} Aventureiro;

typedef struct No{
    Aventureiro dado;
    struct No * prox_no;
} No;

typedef struct {
    No * inicio;
} Lista;

void ler(Aventureiro * av) {
    printf("Insira o nome:\n");
    scanf(" %[^\n]s", av->nome);
    printf("Insira o ID:\n");
    scanf("%d", &av->ID);
}

void add(Lista * lista, Aventureiro av) {
    No * novo = (No *)malloc(sizeof(No));
    novo->dado = av;
    novo->prox_no = lista->inicio;
    lista->inicio = novo;
}

void mostrar(Lista lista) {
      if(lista.inicio == NULL) {
    printf("Lista vazia!\n");
   }else {
         No * po = lista.inicio;
    while(po != NULL) {
        printf("Nome: %s ID: %d\n", po->dado.nome, po->dado.ID);
        po = po->prox_no;
    }
   }
}

void menu() {
    printf("========================\n");
    printf("1 - Adicionar aventureiro:\n");
    printf("2 - Mostrar grupo\n");
    printf("3 - sair\n");
    printf("=====================\n");
}

int main() {
    Lista lista;
    lista.inicio = NULL;
    int op = 0;
    while(op != 3) {
        menu();
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            Aventureiro av;
            ler(&av);
            add(&lista, av);
            break;
        case 2:
            mostrar(lista);
            break;
        case 3:
            op = 3;
            break;
        default:
            break;
        }
    }



    return 0;
}