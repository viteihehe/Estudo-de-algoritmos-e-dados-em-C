#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nickname [50];
} Jogador;

typedef struct No {
    Jogador dado;
    struct No * prox;
} No;

typedef struct {
    No * inicio;
    No * fim;
} Fila;

void ler(Jogador * j) {
    printf("Insira o nome:\n");
    scanf(" %[^\n]s", j->nickname);
    printf("Insira o id:\n");
    scanf("%d", &j->id);
}

void inserir(Fila *f, Jogador j) {
    No * novo = (No *)malloc(sizeof(No));
    novo->dado = j;
    novo->prox = NULL;
    if(f->inicio == NULL) {
        f->inicio = novo;
        f->fim = novo;
    }else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

void mostrar(Fila f) {
    printf("==========================================\n");
    if(f.inicio == NULL) {
        printf("A fila esta vazia\n");
    }else {
        No * aux;
        for(aux = f.inicio; aux != NULL; aux = aux->prox) {
        printf("Nickname: %s, ID: %d\n", aux->dado.nickname, aux->dado.id);
    }
    }
    printf("==========================================\n");
}

Jogador remover(Fila *f) {
    if(f->inicio == NULL) {
        printf("Erro ao remover uma fila vazia!\n");
        Jogador j = {-1, ""};
        return j;
    }else if(f->inicio->prox == NULL){
        No * temp;
        temp = f->inicio;
        Jogador j = temp->dado;
        f->inicio = NULL;
        f->fim = NULL;
        free(temp);
        return j;
    }else {
        No * temp;
        temp = f->inicio;
        Jogador j = temp->dado; 
        f->inicio = temp->prox;
        free(temp);
        return j;
    }
}

int estaVazia(Fila *f) {
    if(f->inicio == NULL) {
        return 1;
    }else {
        return 0;
    }
}

Jogador verInicio(Fila *f) {
    if(estaVazia(f)) {
        Jogador j = {-1, ""};
        return j;
    }else {
        Jogador j = f->inicio->dado;
        return j;
    }
}

void salvarFila(Fila *f, const char* nomeArquivo) {
    FILE *file = fopen(nomeArquivo, "wb");
    if(file == NULL) {
        printf("Erro ao criar arquivo!\n");
    }else {
        No * temp = f->inicio;
        while(temp != NULL) {
            fwrite(&temp->dado, sizeof(Jogador), 1, file);
            temp = temp->prox;
        }
        fclose(file);
    }
}

void carregarFila(Fila *f, const char *nome_arquivo) {
    FILE *file = fopen(nome_arquivo, "rb");
    if(file == NULL) {
        printf("Não foi possivel abrir o arquivo!\n");
        return;
    }
    Jogador e;

    while(fread(&e, sizeof(Jogador), 1, file)) {
        inserir(f, e);
    }
    fclose(file);
}

void menu() {
    printf("==========================================\n");
    printf("1: Inserir item na fila\n");
    printf("2: Mostrar fila\n");
    printf("3: Remover da fila\n");
    printf("4: Verificar se a fila esta vazia\n");
    printf("5: Ver quem e o proximo da fila\n");
    printf("6: Salvar fila em arquivo\n");
    printf("7: Sair\n");
    printf("==========================================\n");
}

int main() {

    Fila fila;
    fila.fim = NULL;
    fila.inicio = NULL;
    Jogador j;
    int op = 1;
    char nome_arquivo [50];
    strcat(nome_arquivo, "matchmaking_queue.bin");

    carregarFila(&fila, nome_arquivo);
    

    while(op) {
        menu();
        scanf("%d", &op);

        switch (op) {
            case 1:
                ler(&j);
                inserir(&fila, j);
                break;
            case 2:
                mostrar(fila);
                break;
            case 3:
                j = remover(&fila);
                if(j.id != -1) {
                    printf("O jogador %s(ID: %d) foi removido da fila e entrou em uma partida\n", j.nickname, j.id);
                }
                break;
            case 4:
                if(!estaVazia(&fila)) {
                    printf("Nao, a fila contem jogadores\n");
                }else {
                    printf("SIM, a fila esta vazia\n");
                }
                break;
            case 5:
                j = verInicio(&fila);
                if(j.id != -1) {
                    printf("O proximo jogador a entrar na partida e: %s (ID: %d)\n", j.nickname, j.id);
                }else {
                    printf("A fila esta vazia!\n");
                }
                break;
            case 6:
                salvarFila(&fila, nome_arquivo);
                break;
            case 7:
                op = 0;
                break;

            default:
                op = 1;
                break;
        }
    }


    return 0;
}