#include <stdio.h>

int main(){
    int a,b,c,d;
    int *pa = &a, *pb = &b, *pc = &c, *pd = &d;

    printf("Insira 4 valores: \n");
    scanf("%d %d %d %d", pa, pb, pc, pd);

    if((*pb > *pc) && (*pd > *pa)&&(*pc+*pd > *pa+*pb)&&(*pc+*pd > 0)&&(*pa+*pb > 0)&&(*pa%2 == 0)){
        printf("Valores aceitos!";)
    }else{
        printf("Valores não aceitos!");
    }


    return 0;
}