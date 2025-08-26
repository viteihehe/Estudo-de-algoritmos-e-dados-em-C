algoritmo "Primos_entre"
var
   x, y,i, j, r : inteiro
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
         para i de x ate y passo 1 faca
            r := 0
            para j de 1 ate i passo 1 faca
               se(i%j = 0)entao
                  r := r+1
               fimse
            fimpara
            se(r = 2)entao
               escreva(i)
            fimse
         fimpara
      fimse
   fimse



fimalgoritmo