#include <stdio.h>

int main() {
    int moedas_coletadas[] = {10,50,20,5,100}, pontuacao_total = 0;
    int *ponteiro_moeda = moedas_coletadas;

        while(ponteiro_moeda != moedas_coletadas + 5){
            pontuacao_total += *ponteiro_moeda;
            ponteiro_moeda++;
        }


            printf("Pontuacao total do nivel: %d", pontuacao_total);

    return 0;
}