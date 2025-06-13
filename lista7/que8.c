#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "portuguese");
  int x, y, cont;
    printf("Insira o primeiro número:\n");
    scanf("%d", &x);
      if(x < 0){
        printf("Valor invalido!\n");
      }else{
        printf("Insira o segundo número:\n");
        scanf("%d", &y);
          if(y < 0){
            printf("Valor invalido!");
          }else{
            if(y < x){
                int temp;
                temp = y;
                y = x;
                x = temp;
            }
            for(int i = x; i <= y; i++){
              cont = 0;
                for(int j = 1; j <= i; j++){
                  if(i%j == 0){
                    cont++;
                  }
                }
            if(cont == 2){
                printf("%d ", i);
            }
            }
          }
      }



    return 0;
}