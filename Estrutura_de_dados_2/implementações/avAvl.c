#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no {
    int valor;
    int balancea;
    struct no *esq;
    struct no *dir;
}No;

int maior(int a, int b) {
    if(a > b) return a;
    return b;
}
int isempty(No *);
No *inserir(No *, int);
int altura(No *);
No *remover(No *, int);
No *busca(No *, int);
void in_ordem(No *);
No *maior_menor(No *raiz) {
    if(!isempty(raiz)) {
        if(raiz->dir != NULL) {
            No *pivo;
            for(pivo = raiz->dir; pivo->esq != NULL; pivo = raiz->esq);
            return pivo;
        } else {
            printf("Não é possivel\n");
        }
    }
  return NULL;
}
No *balan(No *raiz);
No *giro(No *raiz);

int main() {
    srand(time(NULL));
    int v [10];
    for(int i = 0; i < 10; i++) {
        v[i] = (rand() % 20)+1;
    }
    return 0;
}

int isempty(No *raiz) {
    if(raiz == NULL) {
        return 1;
    }
    return 0;
}

No *inserir(No *atual, int valor) {
    if(isempty(atual)) {
        No *novo = (No*)malloc(sizeof(No));
        novo->valor = valor;
        novo->dir = NULL;
        novo->esq = NULL;
        return novo;
    }
    if(valor <= atual->valor) {
        atual->esq = inserir(atual->esq, valor);
    }
    else {
        atual->dir = inserir(atual->dir, valor);
    }
    balan(atual);
    if(atual->balancea >= 2 || atual->balancea <= -2) {
        return atual = giro(atual);
    }
    return atual;
}

int altura(No *raiz) {
    if(!isempty(raiz)) {
        return maior(altura(raiz->esq),
         altura(raiz->dir))+1;
    }
    return -1;
}

No *remover(No *atual, int valor) {
    if(!isempty(atual)) {
        if(valor < atual->valor) {
            atual->esq = remover(atual->esq, valor);
        }
        else if(valor > atual->valor) {
            atual->dir = remover(atual->dir, valor);
        }
        else {
            if(atual->dir == NULL && atual->esq == NULL) {
                free(atual);
                return NULL;
            }
            else if(atual->dir != NULL && atual->esq != NULL) {
                No *pivo = maior_menor(atual);
                atual->valor = pivo->valor;
                atual->dir = remover(atual->dir, pivo->valor);
                return atual;
            }
            else if(atual->esq != NULL) {
                No *filho = atual->esq;
                free(atual);
                return filho;
            } else {
                No *filho = atual->dir;
                free(atual);
                return filho;
            }
        
        }
    }
    balan(atual);
    if(atual->balancea >= 2 || atual->balancea <= -2) {
        return atual = giro(atual);
    }
    return atual;
}

No *busca(No *atual, int valor) {
    if(!isempty(atual)) {
        if(atual->valor == valor) {
            return atual;
        }
        if(valor < atual->valor) {
            return busca(atual->esq, valor);
        }
        else {
            return busca(atual->dir, valor);
        }
    }
    return NULL;
}

void in_ordem(No * raiz) {
    if(!isempty(raiz)) {
        in_ordem(raiz->esq);
        printf("%d ", raiz->valor);
        in_ordem(raiz->dir);
    }
}

No *balan(No *raiz) {
    if(!isempty(raiz)) {
        raiz->balancea = (altura(raiz->esq) - altura(raiz->dir));
    }
    return NULL;
}

No *giro(No *raiz) {
   if(!isempty(raiz)) {
        if(raiz->balancea >= 2) {
            if(raiz->esq->balancea <= -1) {
                //LR
                No * temp = raiz->esq;
                No * novo = temp->dir;
                raiz->esq = novo->dir;
                temp->dir = novo->esq;
                novo->dir = raiz;
                novo->esq = temp;
                return novo;
            }
            else {
                //LL
                 No *novo_topo = raiz->esq;
                raiz->esq = novo_topo->dir;
                novo_topo->dir = raiz;
                return novo_topo;
            }
           
        } else if(raiz->balancea <= -2) {
            if(raiz->dir->balancea >= 1) {
                No *temp = raiz->dir;
                No *novo = temp->esq;
                raiz->dir = novo->esq;
                temp->esq = novo->dir;
                novo->esq = raiz;
                novo->dir = temp;
                return novo;
            }
            else {
                No *filho = raiz->dir;
                raiz->dir = filho->esq;
                filho->esq = raiz;
                return filho;
            }
        }
   }
   return NULL;
}
