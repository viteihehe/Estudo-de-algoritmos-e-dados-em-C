#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char dado;
    struct No * prox;
} No;

typedef struct {
    No * topo;
} Pilha;

Pilha newPilha() {
    Pilha pilha;
    pilha.topo = NULL;
    return pilha;
}

int isEmpty(Pilha *pilha) {
    if(pilha->topo == NULL) {
        return 1;
    }else {
        return 0;
    } 
}

void push(Pilha *pilha, char dado) {
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

void pop(Pilha *pilha) {
    if(!isEmpty(pilha)) {
        No *temp = pilha->topo;
        pilha->topo = temp->prox;
        free(temp);
    }else {
        printf("A pilha está vazia!\n");
    }
}

void mostrar(Pilha pilha) {
    if(!isEmpty(&pilha)) {
        No * pi;
        for(pi = pilha.topo; pi != NULL; pi = pi->prox) {
            printf("%c ", pi->dado);
        }
        printf("\n");
    }else {
        printf("A pilha está vazia!\n");
    }
}

No* top(Pilha pilha) {
    return pilha.topo;
}

void menu() {
    printf("=====================================\n");
    printf("1 - Adicionar Equação\n");
    printf("2 - Remover item\n");
    printf("3 - Mostrar equação\n");
    printf("4 - Validar equação\n");
    printf("5 - Sair\n");
    printf("=====================================\n");
}

int verifica(Pilha pilha) {
    if(!isEmpty(&pilha)) {
        Pilha aux = newPilha();
        int valida = 1;
        int t = 0;
        No *temp;
        for(temp = pilha.topo; temp != NULL; temp = temp->prox) {
            if(temp->dado == '{' || temp->dado == '(' || temp->dado == '[') {
                push(&aux, temp->dado);
            }
            
            if(!isEmpty(&aux)) {
                if(temp->dado == ')' && aux.topo->dado == '(' ||
                temp->dado == ']' && aux.topo->dado == '[' ||
                temp->dado == '}' && aux.topo->dado == '{') {
                    pop(&aux);
                }
            }else {
                return 0;
            }


        }
        
        if(isEmpty(&aux)) {
            return 1;
        }
        return 0;
        
        deletarPilha(&aux);
    }
}

void deletarPilha(Pilha *pilha) {
    if(!isEmpty(pilha)) {
        
        while(pilha->topo != NULL) {
            No *temp = pilha->topo;
            pilha->topo = temp->prox;
            free(temp);
        }
    }
}

void inverte(Pilha *pilha) {
    if(!isEmpty(pilha)) {
        Pilha aux;
        aux.topo = NULL;
        No *temp;
        for(temp = pilha->topo; temp != NULL; temp = pilha->topo) {
            push(&aux, temp->dado);
            pop(pilha);
        }
        pilha->topo = aux.topo;
    }
    return;
}


int main() {
    Pilha pilha = newPilha();
    int op = 1;

    while(op) {
        menu();
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            char eq [50];
            printf("Insira a equacao:\n");
            scanf(" %[^\n]s", eq);
            for(int i = 0; i < strlen(eq); i++) {
                push(&pilha, eq[i]);
            }
            inverte(&pilha);
            break;
        case 2:
            deletarPilha(&pilha);
            break;
        case 3:
            mostrar(pilha);
            break;
        case 4:
            int valida = verifica(pilha);
            if(!valida) {
                printf("A equacao nao e balanceada!\n");
            }else {
                printf("É balanceada!\n");
            }
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