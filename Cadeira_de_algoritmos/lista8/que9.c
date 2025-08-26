#include <stdio.h>
#include <locale.h>

float media(float a, float b, float c);
void conceito(float d);


int main(){
  setlocale(LC_ALL, "portuguese");
  float a, b, c, r;

  printf("Insira a primeira nota:\n");
  scanf("%f", &a);
  printf("Insira a segunda nota:\n");
  scanf("%f", &b);
  printf("Insira a terceira nota:\n");
  scanf("%f", &c);

  r = media(a,b,c);
  printf("Média: %.2f\n", r);
  conceito(media(a,b,c));

    return 0;
}

float media(float a, float b, float c){
    return( (a+b+c)/3);
}
void conceito(float d){
  printf("CONCEITO: \n");
    if(d >= 9){
        printf("A\n");
    }else if (d >= 7){
        printf("B\n");
    }else if(d >=6){
        printf("C\n");
    }else if(d >= 4){
        printf("D\n");
    }else{
        printf("E\n");
    }
}