#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome [100];
    int nivel;
} Membro;

typedef struct No {
    Membro dado;
    struct No * prox;
} No;

typedef struct {
    No * inicio;
} Lista;

void ler(Membro * m) {
    printf("Insira o id:\n");
    scanf("%d", &m->id);
    printf("Insira o nome:\n");
    scanf(" %[^\n]s", m->nome);
    printf("Insira o nivel:\n");
    scanf("%d", &m->nivel);
}

void adicionar_final(Lista * lista, Membro m) {
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

void mostrar_lista(Lista lista) {
    if(lista.inicio == NULL) {
        printf("A lista esta vazia\n");
    }else {
        No * temp = lista.inicio;
        while(temp != NULL) {
            printf("ID: %d, Nome: %s\n", temp->dado.id, temp->dado.nome);
            temp = temp->prox;
        }
    }
}

Lista criar_lista(int n) {
    if(n <= 0) {
        printf("A lista nao pode ser criada com esse tamanho\n");
    }else {
        Lista lista;
        lista.inicio = NULL;
        Membro m;

        for(int i = 0; i < n; i++) {
            ler(&m);
            adicionar_final(&lista, m);
        }
        return lista;
    }
}

void salvar_guild_arquivo(Lista lista) {
    if(lista.inicio == NULL) {
        printf("Nao e possivel salver uma lista vazia!\n");
    }else {
        No * temp;
        FILE* file = fopen("guider_roster.bin", "wb");
        for(temp = lista.inicio; temp != NULL; temp = temp->prox) {
            fwrite(&temp->dado, sizeof(Membro), 1, file);
        }
        fclose(file);
    }
}

int main() {
    Lista lista;
    lista.inicio = NULL;
    int n;
    printf("Insira a quantidade de elementos:\n");
    scanf("%d", &n);

    lista = criar_lista(n);

    mostrar_lista(lista);

    salvar_guild_arquivo(lista);

    return 0;
}