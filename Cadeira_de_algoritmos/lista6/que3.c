#include <stdio.h>
#include <stdlib.h>

int main(){

  float a, b, r;
  char c;
    printf("-------------------\n");
    printf("****CALCULADORA****\n");
    printf("*Soma - +         *\n");
    printf("*Sub - '-'        *\n");
    printf("*Multi - *        *\n");
    printf("*Divi - /         *\n");
    printf("Insira  o caracter para operação desejada:\n");
    scanf("%c", &c);
      printf("Insira o primeiro valor:\n");
      scanf("%d", &a);
      printf("Insira o segundo valor:\n");
      scanf("%d", &b);

     switch(c){
        case '+':
            r = a+b;
            break;
        case '-':
            r = a-b;
            break;
        case '*':
            r = a*b;
            break;
        case '/':
            if(b != 0){
                r = a/b;
            }else{
                printf("Invalido\n");
                exit(0);
            }
            break;
        default:
            printf("Fora dos limites!\n");
            exit(0);
            break;
     }
    printf("Valor calculado: %.2f", r);

    return 0;
}