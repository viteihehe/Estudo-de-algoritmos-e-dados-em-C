#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int ID;
    char nickName [50];
    int pontosDeReputacao;
} Jogador;

int buscarbinaria(int id, Jogador jogadores[], int quantidade) {
    int inicio = 0;
    int fim = quantidade-1;
    while(inicio <= fim) {
        int meio = (inicio+fim)/2;
        if(jogadores[meio].ID == id) {
            return meio;
        }else if(jogadores[meio].ID < id) {
            inicio = meio+1;
        }else {
            fim = meio-1;
        }
    }
    return -1;
}

void menu() {
    printf("=========ESCOLHA UMA OPCAO=========\n");
    printf("1 - Buscar por id\n");
    printf("2 - Sair\n");
    printf("=================================\n");
}



int main() {
    int n, idinicial = 1000, loop = 1, op;
    int *pid = &idinicial;
    printf("Quantos jogadores serão cadastrados?\n");
    scanf("%d", &n);

    Jogador *jogadores = (Jogador *)malloc(n*sizeof(Jogador));
    
    for(int i = 0; i < n; i++) {
        printf("Insira o nickName do jogador %d:\n", i+1);
        scanf(" %[^\n]s", jogadores[i].nickName);
        printf("Insira os pontos de reputação:\n");
        scanf("%d", &jogadores[i].pontosDeReputacao);
        jogadores[i].ID = idinicial++;
    }

    
    while(loop) {
        menu();
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            int tempid;
            printf("Insira o id do jogador que deseja buscar:\n");
            scanf("%d", &tempid);

            int id = buscarbinaria(tempid, jogadores, n);  

            if(tempid != -1) {
                jogadores[id].pontosDeReputacao += 100;
                printf("Nickname: %s, Nova Reputacao: %d\n", jogadores[id].nickName, jogadores[id].pontosDeReputacao);
            }else {
                printf("Jogador com ID %d nao encontrado.\n", tempid);
            }
            break;
        case 2:
            printf("Encerrando o programa!\n");
            loop = 0;
            break;
        default:
            printf("Entrada invalida\n");
            break;
        }
   }
        free(jogadores);
    return 0;
}