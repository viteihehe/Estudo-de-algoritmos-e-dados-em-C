#include <stdio.h>
#include <stdlib.h>

typedef enum {
    APROVADO,
    REPROVADO,
} ESTADO;

typedef enum {
    A,
    B,
    C,
    D,
} TURMA;

typedef struct {
    TURMA turma;
    float notas[3];
    float frequencia;
    ESTADO estado;
} Boletim;

typedef struct {
    int matricula;
    char nome[100];
    Boletim boletim
} Aluno;

void cadastro(Aluno *aluno, int n);
float media(Aluno aluno);
void aprovado(Aluno aluno);
void exibicao(Aluno *alunos, int n, TURMA turma, float *mediaturma, float *mediafrequencia);
void menu(float *media, float *frequencia, int n, Aluno *alunos);

int main() {
    int n;
    float *media = (float *)malloc(sizeof(float));
    float *frequencia = (float *)malloc(sizeof(float));
    *media = 0;
    *frequencia = 0;

    printf("Insira a quantidade de alunos:\n");
    scanf("%d", &n);

    Aluno *alunos = (Aluno *)calloc(n, sizeof(Aluno));

    if(alunos == NULL) {
        exit(0);
    }

    cadastro(alunos, n);

    menu(media, frequencia, n, alunos);

    free(alunos);    
    free(media);
    free(frequencia);

    return 0;
}

void cadastro(Aluno *aluno, int n) {

    for(int i = 0; i < n; i++) {
        printf("Insira o nome do %d aluno:\n", i+1);
        scanf(" %[^\n]s", aluno[i].nome);
        

        printf("Insira a matricula: (inteiro)\n");
        scanf("%d", &aluno[i].matricula);

        char temp;
        printf("Insira a turma do aluno: (minusculo)\n");
        scanf(" %c", &temp);
            switch (temp)
            {
            case 'a':
                aluno[i].boletim.turma = A;
                break;
            case 'b':
                aluno[i].boletim.turma = B;
                break;
            case 'c':
                aluno[i].boletim.turma = C;
                break;
            case 'd':
                aluno[i].boletim.turma = D;
                break;
            
            default:
                printf("Essa turma não existe\n");
                break;
            }

        for(int j = 0; j < 3; j++) {
            printf("Insira a %d nota:\n", j+1);
            scanf("%f", &aluno[i].boletim.notas[j]);
        }

        printf("Insira a frequencia: (porcentagem)\n");
        scanf("%f", &aluno[i].boletim.frequencia);

        aprovado(aluno[i]);
        
    }

}

void aprovado(Aluno aluno) {
    float tempmedia = media(aluno);
    
    if(tempmedia >= 7 && aluno.boletim.frequencia >= 75) {
        aluno.boletim.estado = APROVADO;
    }else {
        aluno.boletim.estado = REPROVADO;
    }
}

float media(Aluno aluno) {
    float media = 0;
    for(int i = 0; i < 3; i++) {
        media += aluno.boletim.notas[i];
    }
    return media/3;
}

void exibicao(Aluno *alunos, int n, TURMA turma, float *mediaturma, float *mediafrequencia) {

    int cont = 0;
    for(int i = 0; i < n; i++) {
        if(alunos[i].boletim.turma == turma) {
            

            printf("Nome: %s\n", alunos[i].nome);
            printf("Matricula: %d\n", alunos[i].matricula);
            if(alunos[i].boletim.estado == APROVADO) {
                printf("Estado: APROVADO!\n");

            }else {
                printf("Estado: REPROVADO :(\n");
            }
            cont++;
            *mediaturma += media(alunos[i]);
            *mediafrequencia += alunos[i].boletim.frequencia;

        }
        
    }

    *mediafrequencia = *(mediafrequencia)/cont;
    *mediaturma = *(mediaturma)/cont;

}

void menu(float *media, float *frequencia, int n, Aluno *alunos) {
     for(int i = 65; i < 69; i++) {

        printf("=================================\n");
         printf("Turma %c:\n", (char) i);
    

        *media = 0;
        *frequencia = 0;
        exibicao(alunos, n, D, media, frequencia);

        printf("Media da turma: %f\n", *media);
        printf("Media da frequencia: %f \n", *frequencia);

        printf("=================================\n");

     }
}