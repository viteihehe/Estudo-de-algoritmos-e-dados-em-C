algoritmo "Primo"
var
   i, a, b : inteiro
inicio
      i := 1
      b := 0
      escreval("Insira um número:")
      leia(a)
      enquanto (i <= a)faca
        se(a%i = 0)entao
             b := b+1
        fimse
        i := i+1
      fimenquanto
      Se( b = 2)entao
          escreval("O número é primo")
      senao
          escreval("O número não é primo")
      fimse
fimalgoritmo