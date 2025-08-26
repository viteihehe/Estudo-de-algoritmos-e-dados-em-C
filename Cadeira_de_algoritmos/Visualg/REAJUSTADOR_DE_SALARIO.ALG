algoritmo "Reajustador_de_salario"

var

   S,r,si : real

inicio
      escreval("Insira o salário inicial:")
      leia(si)
      
      se(si < 2000)entao
            r := (si*0.15)
            S := (si+r)
      senao
           se(si >=2000) e (si <5000)entao
                 r := (si*0.10)
                   S := (si+r)
           senao
                r := (si*0.05)
                   S := (si+r)
           fimse
      fimse

      escreva("O salário reajustado é de ", S:2:2,"R$")

fimalgoritmo