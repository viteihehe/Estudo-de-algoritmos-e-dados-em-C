#include <stdio.h>
#include <stdlib.h>


typedef struct No {
    int valor;
    int nfilhos;
    struct No** filhos;
} No;

No* criar_raiz(int valor);
void add_filho(No *, int);
void liberar_arvore(No *);

int main() {
    No * raiz = criar_raiz(1);
    add_filho(raiz, 3);
    add_filho(raiz, 2);
    add_filho(raiz, 5);
    

    return 0;
}

void liberar_arvore(No * raiz) {
    for(size_t i = 0; i < raiz->nfilhos; i++) {
        liberar_arvore(raiz->filhos[i]);
    }
    free(raiz);
}

No* criar_raiz(int valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->nfilhos = 0;
    novo_no->filhos = NULL;
    return novo_no;
}

void add_filho(No * pai, int valor) {
    if(pai->nfilhos <= 3) {
        pai->nfilhos++;
        pai->filhos = (No**)realloc(pai->filhos, pai->nfilhos*sizeof(No*));
        pai->filhos[pai->nfilhos - 1] = criar_raiz(valor);
        return;
    } else {
        printf("Limite de filhso excedido!\n");
    }
    return;
}

