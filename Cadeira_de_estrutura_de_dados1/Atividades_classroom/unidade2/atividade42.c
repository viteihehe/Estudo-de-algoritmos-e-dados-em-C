#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int resolucao_x;
    int resolucao_y;
    float volume_som;
} Configuracao;

int main() {
    Configuracao config;

    FILE *file = fopen("./conf.txt", "r");
    if(file == NULL) {
        printf("Ouve um erro ao abrir o arquivo!\n");
        system("pause");
        exit(1);
    }
    fscanf(file, "%d %d %f", &config.resolucao_x, &config.resolucao_y, &config.volume_som);
    printf("Configuracoes carregadas:\nResolucao: %d x %d\nVolume: %1.f\n", config.resolucao_x, config.resolucao_y, config.volume_som);

    fclose(file);

    return 0;
}