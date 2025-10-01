#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float notas [3];
    char nota;
} Boletim;

typedef struct {
    char nome [100];
    int matricula;
    Boletim b;

} Alunos;

float media(Alunos aluno) {
    float media = 0;
    for(int i = 0; i < 3; i++) {
        media += aluno.b.notas[i];
    }
    return media;
}

void conceito(Alunos *alunos, int n) {
    for(int i = 0; i < n; i++) {
        float tempmedia = media(alunos[i]);
        if(tempmedia >= 9) {
            alunos[i].b.nota = 'A';
        }else if(tempmedia >= 8) {
            alunos[i].b.nota = 'B';
        }else if(tempmedia >= 7) {
            alunos[i].b.nota = 'C';
        }else if(tempmedia >= 6) {
            alunos[i].b.nota = 'D';
        }else if(tempmedia >= 5) {
            alunos[i].b.nota = 'E';
        }else {
            alunos[i].b.nota = 'F';
        }
    }
}


int main() {
    int n;

    printf("Insira a quantidade de alunos:\n");
    scanf("%d", &n);

    Alunos *alunos = (Alunos *)calloc(n, sizeof(Alunos));

    if(alunos == NULL) {
        exit(0);
    }

    for(int i = 0; i < n; i++) {
        printf("Insira a matricula do aluno: (inteiro)\n");
        scanf("%d", &alunos[i].matricula);
        printf("Insira o nome do aluno:\n");
        scanf(" %[^\n]s", alunos[i].nome);
            for(int j = 0; j < 3; j++) {
                printf("Insira a %d nota:\n", j+1);
                scanf("%f", &alunos[i].b.notas[j]);
            }
    }

    conceito(alunos, n);

    int conceitos [6] = {0,0,0,0,0,0};
    for(int i = 0; i < n; i++) {
        if(alunos[i].b.nota == 'A') {
            conceitos[0]++;
        }else if(alunos[i].b.nota == 'B') {
            conceitos[1]++;
        }else if(alunos[i].b.nota == 'C') {
            conceitos[2]++;
        }else if(alunos[i].b.nota == 'D') {
            conceitos[3]++;
        }else if(alunos[i].b.nota == 'E') {
            conceitos[4]++;
        }else {
            conceitos[5]++;
        }
    }

    printf("Tabela:\n");
    printf("A - %d\n", conceitos[0]);
    printf("B - %d\n", conceitos[1]);
    printf("C - %d\n", conceitos[2]);
    printf("D - %d\n", conceitos[3]);
    printf("E - %d\n", conceitos[4]);
    printf("F - %d\n", conceitos[5]);

    free(alunos);

    return 0;
}