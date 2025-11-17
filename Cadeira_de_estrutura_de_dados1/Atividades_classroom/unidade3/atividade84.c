#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char titulo [50];
    char status [50];
} Missao;

typedef struct No {
    Missao dado;
    struct No * prox_no;
} No;

typedef struct {
    No * inicio;
} Lista;

void ler(Missao * m) {
    printf("Insira o titulo:\n");
    scanf(" %[^\n]s", m->titulo);
    printf("Insira o status:\n");
    scanf(" %[^\n]s", m->status);
    printf("Insira o id:\n");
    scanf("%d", &m->id);
}

void adicionar_missao(Lista * Lista, Missao m) {
    No * novo = (No *)malloc(sizeof(No));
    novo->dado = m;
    novo->prox_no = NULL;
    if(Lista->inicio == NULL) {
        Lista->inicio = novo;
    }else {
        No * temp = Lista->inicio;
        while(temp->prox_no != NULL) {
            temp = temp->prox_no;
        }
        temp->prox_no = novo;
    }
}

void mostrar_missao(Lista lista) {
    No * temp = lista.inicio;
    if(temp == NULL) {
        printf("Lista de missões vazia!\n");
    }else {
        while(temp != NULL) {
            printf("Titulo: %s\nStatus: %s ID: %d\n", temp->dado.titulo, temp->dado.status, temp->dado.id);
            temp = temp->prox_no;
        }
    }
}

No * buscar_missao(Lista lista, int id) {
    if(lista.inicio == NULL) {
        printf("A lista está vazia!\n");
    }else {
        No* temp;
        for(temp = lista.inicio; temp != NULL && temp->dado.id != id; temp = temp->prox_no);
        return temp;
    }
    return NULL;
}

void menu() {
    printf("===================================\n");
    printf("1 - Adicionar missao: Adiciona uma nova missão ao final do diário\n");
    printf("2 - Mostrar Missões: Exibe todas as missões presentes no diário.\n");
    printf("3 - Buscar Missão por ID: Pede ao usuário um ID e procura a missão\n");
    printf("4 - Sair: Encerra o programa.\n");
    printf("===================================\n");
}
int main() {
    Lista lista;
    lista.inicio = NULL;
    Missao m;
    int op = 0, id;

    while(op != 4) {
        menu();
        scanf("%d", &op);
        switch (op) {
            case 1:
                ler(&m);
                adicionar_missao(&lista, m);
                break;
            case 2:
                mostrar_missao(lista);
                break;
            case 3:
                printf("Insira o id desejado:\n");
                scanf("%d", &id);
                No * temp = buscar_missao(lista, id);
                if(temp != NULL) {
                    printf("Titulo: %s\nStatus: %s ID: %d\n", temp->dado.titulo, temp->dado.status, temp->dado.id);
                }else {
                    printf("Item indisponivél\n");
                }
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