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
    printf("4: Consultar proximo feitico\n");
    printf("5: Salvar sequencia no grimorio\n");
    printf("6: Vetificar Status da Pilha\n");
    printf("7: Inverter ordem dos feiticos\n");
    printf("8: Finalizar a sequencia de comando e sair\n");
    printf("==========================================\n");
}

int vazia(Pilha *p) {
    if(p->topo == NULL) {
        return 1;
    }else {
        return 0;
    }
}

void mostrar(Pilha pilha) {
    No * temp = pilha.topo;
    printf("==========================================\n");
    if(vazia(&pilha)) {
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
    if(vazia(pilha)) {
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

Feitico top(Pilha p) {
    if(!vazia(&p)) {
        return p.topo->dado;
    }else {
        Feitico f;
        f.custo_mana = -1;
        char erro [5] = {'E', 'R' ,'R', 'O', '\0'};
        strcpy(f.nome, erro);
        return f;
    }
}

void inverter_pilha(Pilha *p) {
    if(!vazia(p)) {
        Pilha aux;
        aux.topo = NULL;
        No * temp;
        for(temp = p->topo; temp != NULL; temp = p->topo) {
            push(&aux, temp->dado);
            pop(p);
        }
        p->topo = aux.topo;
        printf("Ordem dos feiticos invertida!\n");
    }else {
        printf("Nao a nada para inverter\n");
    }
}

void salvar_pilha_em_arquivo(Pilha *p, const char* nome_arquivo) {
   if(!vazia(p)) {
    FILE* file = fopen(nome_arquivo, "wb");
    No * temp;
    for(temp = p->topo; temp != NULL; temp = temp->prox) {
        fwrite(&temp->dado, sizeof(Feitico), 1, file);
    }
    fclose(file);
    printf("Arquivo salvo com sucesso\n");
   }else {
    printf("Nao a nada para salvar\n");
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
                f = top(pilha);
                printf("Topo: %s, Custo de mana: %d\n", f.nome, f.custo_mana);
                break;
            case 5:
                char nome_arquivo [50] = {""};
                strcat(nome_arquivo, "grimorio.bin");
                salvar_pilha_em_arquivo(&pilha, nome_arquivo);
                break;
            case 6:
                if(vazia(&pilha)) {
                    printf("Vazia!\n");
                }else {
                    printf("Nao esta vazia!\n");
                }
                break;
            case 7:
                inverter_pilha(&pilha);
                break;
            case 8:
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