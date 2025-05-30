algoritmo "Fatorial primo"
var
   i, v, a, b : inteiro
inicio
      i := 1
      escreval("Fatoriais dos impares de 1 até 11")
      enquanto ( i <= 11)faca
        se(i%2 <> 0)entao
          a := 1
          para v de i ate 1 passo -1 faca
               a := a*v
          fimpara
             escreval(i, "! =", a)
        fimse
        
        i:= i+1
      fimenquanto

fimalgoritmo