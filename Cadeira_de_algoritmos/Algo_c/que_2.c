#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "portuguese");

    printf("Pão de queijo!\nQueijo \nde pão!\n \tDe queijo pão!\n De pão,\n \tqueijo!\n");
   
    return 0;
}