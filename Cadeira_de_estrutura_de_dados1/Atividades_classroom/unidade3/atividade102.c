#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int custo_mana;
    char nome [100];
} Feitico;

typedef struct No {
    Feitico dado;
    struct No * prox;
} No;

typedef struct {
    No * topo;
} Pilha;

void ler(Feitico * f) {
    printf("Insira o nome:\n");
    scanf(" %[^\n]s", f->nome);
    printf("Insira o custo de mana:\n");
    scanf("%d", &f->custo_mana);
}

void push(Pilha * pilha, Feitico f) {
    No * novo = (No *)malloc(sizeof(No));
    novo->dado = f;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

void menu() {
    printf("==========================================\n");
    printf("1: Adicionar um novo feitico a pilha de comandos\n");
    printf("2: Lancar Proximo Feitico\n");
    printf("3: Mostrar Pilha de Comandos\n");
    printf("4: Finalizar a sequencia de comando e sair\n");
    printf("==========================================\n");
}

void mostrar(Pilha pilha) {
    No * temp = pilha.topo;
    printf("==========================================\n");
    if(pilha.topo == NULL) {
        printf("A pilha esta vazia\n");
    }else {
        while(temp != NULL) {
        printf("Feitico: %s, Custo de mana: %d\n", temp->dado.nome, temp->dado.custo_mana);
        temp = temp->prox;
    }
    }
    printf("==========================================\n");
}

Feitico pop(Pilha * pilha) {
    if(pilha->topo == NULL) {
        printf("A lista esta vazia!\n");
        Feitico f;
        f.custo_mana = -1;
        char erro [5] = {'E', 'R' ,'R', 'O', '\0'};
        strcpy(f.nome, erro);
        return f;
    }else {
        No * temp = pilha->topo;
        pilha->topo = temp->prox;
        Feitico f = temp->dado;
        free(temp);
        return f;
    }
}

void liberar_pilha(Pilha *p) {
    No * temp;
    while(p->topo != NULL) {
        temp = p->topo;
        p->topo = temp->prox;
        free(temp);
    }
}

int main() {
    Pilha pilha;
    pilha.topo = NULL;
    Feitico f;
    int op = 1;

    while(op) {
        menu();
        scanf("%d", &op);

        switch (op) {
            case 1:
                ler(&f);
                push(&pilha, f);
                break;
            case 2:
                f = pop(&pilha);
                printf("Feitico: %s lancado com sucesso!\n", f.nome);
                break;
            case 3:
                mostrar(pilha);
                break;
            case 4:
                liberar_pilha(&pilha);
                op = 0;
                break;
            default:
                op = 1;
                break;
        }
    }
    return 0;
}