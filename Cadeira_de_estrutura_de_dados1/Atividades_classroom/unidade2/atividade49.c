#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *file = fopen("level_1_map.dat", "r");
    if(file == NULL) {
        printf("ERRO CRITICO: Nao foi possivel carregar os dados do mapa.\n");
        perror("O arquivo nao foi encontrado ou nao existe\n");
        exit(1);
    }

    return 0;
}