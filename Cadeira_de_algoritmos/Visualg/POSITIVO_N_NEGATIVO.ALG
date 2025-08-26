algoritmo "Positivo_N_Negativo"

var

   n : real

inicio
      escreval("Informe o número desejado")
      leia(n)

      se(n<0)entao
        escreva("Seu número é negativo")
      senao
        se(n>0)entao
            escreva("Seu número é positivo")
      senao
           escreva("Seu número é neutro")
        fimse
      fimse

fimalgoritmo