algoritmo "Divisibilidade"

var

   a, b : inteiro
   
inicio

      escreval("Inisira o numerador")
      leia(a)
      escreval("Inisira o denomidador")
      leia(b)
      
      se(b = 0)entao
           escreva("Não é possivel realizar a divisão")
      senao
        se(a%b = 0)entao
          escreva("É possivel realizar a divisão")
        senao
          escreva("Não é possivel realizar a divisão")
        fimse
      fimse

fimalgoritmo

      