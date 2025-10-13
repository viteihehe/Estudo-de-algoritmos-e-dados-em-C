#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome [50];
    int nivel;
    int highScore;

} PlayerProfile;

int main() {
    
    PlayerProfile player;
    FILE *file = fopen("profiles.dat", "rb");
    if(file == NULL) {
        printf("Erro ao abrir o arquivo!\a\a");
        exit(0);
    }

    while(fread(&player, sizeof(PlayerProfile), 1, file)) {
        if(player.highScore > 10000) {
            printf("%s\nRank: Mestre do Jogo\n", player.nome);
        }else if(player.highScore > 5000) {
            printf("%s\nRank: Veterano\n", player.nome);
        }else{
            printf("%s\nRank: Aspirante\n", player.nome);
        }
    }

    fclose(file);


    return 0;
}