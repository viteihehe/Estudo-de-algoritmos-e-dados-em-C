algoritmo "Soma_pares"
var
   i, r : inteiro
inicio
      r := 0
      i := 1
      escreval("número de 1 a 500")
      
        enquanto (i <= 500)faca
           se(i%2 = 0)entao
             r := r+i
           fimse
           i := i+1
        fimenquanto
      escreva("Valor da soma dos pares de 1 a 500 é:", r)
fimalgoritmo