#include <stdio.h>
#include <locale.h>

int main(){
  setlocale(LC_ALL, "portuguese");
  
int n = 2, m = 2, A[n][m], B[n][m];

    printf("Insira um valor natural para as linhas:\n");
    scanf("%d", &n);
    printf("Insira um valor natural para as colunas:\n");
    scanf("%d,", &m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("insira o %dº valor da linha %d\n", j+1, i+1);
            scanf("%d", &A[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
           B[i][j] = A[i][j]*3;
        }
    }

   for(int i = 0; i < 4; i++){
    for(int j = 0;  j < 2; j++){
        printf("A:  %d B: %d \t\n", A[i][j], B[i][j]);
        
    }
 }

    return 0;
}