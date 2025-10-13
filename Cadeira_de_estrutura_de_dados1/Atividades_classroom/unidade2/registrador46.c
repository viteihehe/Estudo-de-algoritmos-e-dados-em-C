#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome [50];
    int nivel;
    int highScore;

} PlayerProfile;

int main() {
    
    PlayerProfile player;
    FILE *file = fopen("profiles.dat", "wb");
    if(file == NULL) {
        printf("Erro ao abrir o arquivo!\a\a");
        exit(0);
    }

    int n;
    printf("Insira a quantidade de jogadores:\n");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        char tempnome [50];
        int tempnivel, tempidade;
        printf("Insira o nome do jogador:\n");
        scanf(" %s", player.nome);
        printf("Insira o nivel:\n");
        scanf("%d", &player.nivel);
        printf("Insira o score:\n");
        scanf("%d", &player.highScore);

        fwrite(&player, sizeof(PlayerProfile), 1, file);
        fflush(file);
    }

    fclose(file);


    return 0;
}