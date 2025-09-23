#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"portuguese");
    int i;

    printf("Insira a sua idade:\n");
    scanf("%d", &i);
      printf("Você tem aproximadamente %d dias de vida", i*365);
    return 0;
}