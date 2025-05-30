algoritmo "Lista_média"
var
 i : inteiro
 n : caractere
 a, b, c, r : real
inicio
      para i de 1 ate 10 passo 1 faca
           escreval("Insira seu nome:")
           leia(n)
             escrevaL("Insira a 1º nota:")
             leia(a)
             escrevaL("Insira a 2º nota:")
             leia(b)
             escrevaL("Insira a 3º nota:")
             leia(c)
           r := (a+b+c)/3
           se(r >= 7)entao
                escreval(n, " voce foi aprovado com média:", r)
           senao
                escreval(n, " voce foi reprovado com média: ", r)
           fimse
      fimpara
           
fimalgoritmo