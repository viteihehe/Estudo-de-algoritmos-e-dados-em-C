#include <stdio.h>
#include <locale.h>

int main(){
  setlocale(LC_ALL, "portuguese");
  float me, a;
  char con;
  for(int i = 0; i <= 10; i++){
    me = 0;
    printf("Insira a notas abaixo do aluno %d\n", i+1);
      for(int j = 0; j < 3; j++){
        printf("Coloque a %d nota:\n", j+1);
         scanf("%f", &a);
         me += a;
      }
    me = me/3;

    if(me >= 9){
    con = 'A';
    }else if(me >= 7){
        con = 'B';
    }else if(me >= 6){
        con = 'C'; 
    }else if(me >= 4){
        con = 'D';
    }else{
        con = 'E';
    }

printf("Aluno %d média: %.2f com conceito: %c\n", i+1, me, con);
printf("\n");
  
  }

    return 0;
}