#include <stdio.h>

int main(){
    float a1,a2,a3,af,mp,mf;

      printf("Insira a nota da primeira prova:\n");
      scanf("%f", &a1);
      
      printf("Insira a nota da segunda prova:\n");
      scanf("%f", &a2);
      
      printf("Insira a nota da terceira prova:\n");
      scanf("%f", &a3);

      mp = (a1+a2+a3)/3;

      if(mp >= 7){
        printf("Aprovado com media: %.2f", mp);
      }else if((mp >= 3.5) && (mp < 7)){
            printf("Insira a nota da prova final\n");
            scanf("%f", &af);

            mf = ((6*mp)+(4*af))/10;

            if(mf >= 5){
                printf("O aluno foi aprovado com media final %.2f\n", mf);
            }else{
                printf("O aluno foi reprovado devido a media %.2f", mf);
            }
      }else{
            printf("O aluno foi reprovado devido a media %.2f", mp);
      }


    return 0;
}