#include <stdio.h>
#include <stdlib.h>

int main(){
    int c,q;
    float v;

      printf("----------------------------------\n");
      printf("|************CARDAPIO*************|\n");
      printf("| CODIGO |   ESPECIF.  | PRE. UNI.|\n");
      printf("|  100   | Chach.quen. |   10.00  |\n");
      printf("|  101   |    Bauru    |   12.00  |\n");
      printf("|  102   |   X-salada  |   15.00  |\n");
      printf("|  103   |  Hamburguer |   18.00  |\n");
      printf("|  104   | Refrigerante|   05.00  |\n");
      printf("----------------------------------\n");

    printf("Insira o codigo:\n");
    scanf("%d", &c);
    printf("Insira a quantidade:\n");
    scanf("%d", &q);

    switch(c){
        case 100:
          v = q*10;
          break;
        case 101:
          v = q*12;
          break;
        case 102:
          v = q*15;
          break;
        case 103:
          v = q*18;
        case 104:
          v = q*18;
        default:
          printf("Valor invalido!!\n");
          exit(0);
          break;
    }

    printf("Valor a ser pago: %.2f R$\n", v);

    return 0;
}

/*ÓDIGO DO ITEM ESPECIFICAÇÃO PREÇO UNITÁRIO
100 Cachorro quente 10,00
101 Bauru 12,00
102 X-Salada 15,00
103 Hambúrguer 18,00
104 Refrigerante (lata) 5,00*/