#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

char b[20] = "./livros.dat";
char bn[20] = "bPorNome.dat";

typedef enum
{
    INDISPONIVEL,
    DISPONIVEL,
} Disponibilidade;

typedef struct
{
    char nome[50];
    int ID;
    int dias_restantes;
    Disponibilidade disponibilidade;
} Livro;

void menu()
{
    printf("=========ESCOLHA UMA OPCAO=========\n");
    printf("1 - Cadastrar\n");
    printf("2 - Buscar por id\n");
    printf("3 - Busca por titulo\n");
    printf("4 - Devolucao mais proxima\n");
    printf("5 - Sair\n");
    printf("=================================\n");
}

int contar()
{
    int auxi = 0;
    Livro livro;
    FILE *file = fopen(b, "rb");
    if (file == NULL)
    {
        return 0;
    }
    fseek(file, 0, SEEK_END);
    long tamanho = ftell(file);
    rewind(file);
    fclose(file);
    return (tamanho / sizeof(Livro));
}

void cadastrar(int quantLivros)
{
    Livro livro;
    printf("Insira o titulo do livro:\n");
    scanf(" %[^\n]s", livro.nome);
    livro.ID = quantLivros + 1;
    livro.disponibilidade = DISPONIVEL;
    FILE *file = fopen(b, "ab");
    fwrite(&livro, sizeof(Livro), 1, file);
    fclose(file);
}

int buscaBinariaId(int tamanho, int id)
{
    Livro *livros = (Livro *)malloc(tamanho * sizeof(Livro));
    FILE *file = fopen(b, "rb");
    fread(livros, sizeof(Livro), tamanho, file);
    fclose(file);

    int inicio = 0, fim = tamanho - 1, meio, indice = 0;
    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;
        if (livros[meio].ID == id)
        {
            free(livros);
            return meio;
        }
        else if (livros[meio].ID < id)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }
    free(livros);
    return -1;
}

void caixaBaixa(char *texto[]) {
    for(int i = 0; i < strlen(texto); i++) {
        texto[i] = (unsigned char) tolower(texto[i]);
    }
}

void ordenacaoAlfabetica(int tamanho) {
    Livro *livros = (Livro *)malloc(tamanho*sizeof(Livro));
    FILE *file = fopen(b, "rb");
    fread(livros, sizeof(Livro), tamanho, file);
    fclose(file);

    for(int i = 0; i < tamanho-1; i++) {
        for(int j = i+1; j < tamanho; j++) {
            char temp [50] = "";
            char temp2 [50] = "";

            strcat(temp, livros[i].nome);
            strcat(temp2, livros[j].nome);

            caixaBaixa(temp);
            caixaBaixa(temp2);

            if(temp[0] > temp2[0]) {
                Livro tempLivro = livros[i];
                livros[i] = livros[j];
                livros[j] = tempLivro;
            }
        }
    }
    file = fopen(bn, "wb");
    fwrite(livros, sizeof(Livro), tamanho, file);
    fclose(file);
    free(livros);
}

void listarOrdemAlfabetica(int tamanho, char letra) {
    ordenacaoAlfabetica(tamanho);
    Livro livro;
    char letraM = (unsigned char) tolower(letra);
    char letram = (unsigned char) toupper(letra);
    FILE *file = fopen(bn, "rb");
    while(fread(&livro, sizeof(Livro), 1, file)) {
        if(livro.nome[0] == letram || livro.nome[0] == letraM) {
            printf("Titulo: %s\n", livro.nome);
            printf("ID: %d\n", livro.ID);
        }
    }
    fclose(file);
}

int devolucaoProxima(int tamanho) {
    FILE *file = fopen(b, "rb");
    Livro *livros = (Livro *)malloc(tamanho*sizeof(Livro));
    fread(livros, sizeof(Livro), tamanho, file);
    fclose(file);
    int menor = 0;
    for(int i = 0; i < tamanho; i++) {
        if(livros[i].dias_restantes < livros[menor].dias_restantes && livros[i].dias_restantes != 0) {
            menor = i;
        }
    }
    free(livros);
    return menor;
}

int main()
{   
    srand(time(NULL));
    int op, loop = 1;
    int quantLivros = 0;
    FILE *file = NULL;

    quantLivros = contar();

    while (loop)
    {
        menu();
        printf("Insira a opcao desejada:\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            int n;
            printf("Quantos livros deseja adicionar:\n");
            scanf("%d", &n);
            if (n <= 0)
            {
                printf("Invalido!\n");
                break;
            }
            for (int i = 0; i < n; i++)
            {
                cadastrar(quantLivros);
                quantLivros++;
            }

            break;
        case 2:
            quantLivros = contar();
            if (quantLivros != 0)
            {
                int tempid;
                printf("Insira o id:\n");
                scanf("%d", &tempid);

                int indice = buscaBinariaId(quantLivros, tempid);
                if (indice != -1)
                {
                    file = fopen(b, "rb");
                    Livro livros[quantLivros];
                    fread(livros, sizeof(Livro), quantLivros, file);
                    fclose(file);
                    printf("Titulo: %s\n", livros[indice].nome);
                    if (livros[indice].disponibilidade == DISPONIVEL)
                    {
                        char resp;
                        printf("O livro esta disponivel! Deseja pega-lo?(s/n)\n");
                        scanf(" %c", &resp);
                        if (resp == 's')
                        {
                            livros[indice].disponibilidade = INDISPONIVEL;
                            livros[indice].dias_restantes = rand() % 15;
                            file = fopen(b, "wb");
                            fwrite(livros, sizeof(Livro), quantLivros, file);
                            fclose(file);
                        }
                    }
                    else
                    {
                        printf("Se encontra indisponivel no momento. Aguarde %d dias\n", livros[indice].dias_restantes);
                    }
                }
            }

            break;
        case 3:
            quantLivros = contar();
            if(quantLivros != 0) {
                char tempchar;
                printf("Insira uma letra:\n");
                scanf(" %c", &tempchar);
                if(tempchar <= 'a' || tempchar >= 'z' || tempchar <= 'A' || tempchar >= 'Z' ) {
                    printf("======LIVROS=====\n");
                    listarOrdemAlfabetica(quantLivros, tempchar);
                }else {
                    printf("Insira um caracter valido!\n");
                }
                
            }
            break;
        case 4:
            quantLivros = contar();
            Livro *livros = (Livro *)malloc(quantLivros*sizeof(Livro));
            file = fopen(b, "rb");
            fread(livros, sizeof(Livro), quantLivros, file);
            fclose(file);
            int menor = devolucaoProxima(quantLivros);
            printf("Titulo: %s\n", livros[menor].nome);
            printf("Dias restantes: %d\n", livros[menor].dias_restantes);
            free(livros);
            break;

        case 5:
            printf("Encerrando o programa!\n");
            loop = 0;
            break;

        default:
            printf("Opcao invalida!\n");
            break;
        }
    }

    return 0;
}