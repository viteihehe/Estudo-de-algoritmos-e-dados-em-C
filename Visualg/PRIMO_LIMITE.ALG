algoritmo "Primo_limite"
var
   x, y, a, b, c : inteiro
inicio
   escreval("Insira o primeiro limite:")
   leia(x)
   se(x <= 0)entao
      escreval("Valor invalido")
   senao
      escreval("Insira o segundo limite:")
      leia(y)
      se(y <= x)entao
         escreval("Valor invalido")
      senao
         para a de x ate y passo 1 faca
              c := 0
            para b de 1 ate a passo 1 faca
               se(a%b = 0)entao
                  c := c+1
               fimse
            fimpara
              se(c = 2)entao
                     Escreva(a)
                  fimse
         fimpara
      fimse
   fimse

fimalgoritmo