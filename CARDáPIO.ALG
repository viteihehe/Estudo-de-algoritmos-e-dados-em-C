algoritmo "Cardápio"
var
   p : real
   q,c : inteiro
inicio


   escreval(" ________________________________________________________")
   escreval("|Cardapio:                                               |")
   escreval("|________________________________________________________|")
   escreval("|Codigo do item |   Especificação   |  Preço Unitário(R$)|")
   escreval("|---------------|-------------------|--------------------|")
   escreval("|     100       | Cachorro quente   |        10,00       |")
   escreval("|---------------|-------------------|--------------------|")
   escreval("|     101       | Bauro             |        12,00       |")
   escreval("|---------------|-------------------|--------------------|")
   escreval("|     102       | X-Salada          |        15,00       |")
   escreval("|---------------|-------------------|--------------------|")
   escreval("|     103       | Hambúrguer        |        18,00       |")
   escreval("|---------------|-------------------|--------------------|")
   escreval("|     104       | Refrigerante(lata)|        05,00       |")
   escreval("|---------------|-------------------|--------------------|")
   escreval("|________________________________________________________|")
   escreval("")
   escreval("Insira o código do item desejado:")
   escreval("")
   leia(c)
   escreval("")
   se(c >= 100) e (c <105)entao
   escreval("Insira a quantidade desejada:")
   escreval("")
   leia(q)
   escreval("")
   fimse
   
          escolha(c)
               caso 100
                    p := q*10
                     escreva("Valor a ser pago: ", p, "R$")
                      escreval("")
                     
               caso 101
                    p := q*12
                     escreva("Valor a ser pago: ", p, "R$")
                      escreval("")
                      
               caso 102
                    p := q*15
                     escreva("Valor a ser pago: ", p, "R$")
                      escreval("")
                      
               caso 103
                    p := q*18
                     escreva("Valor a ser pago: ", p, "R$")
                      escreval("")
                      
               caso 104
                    p := q*5
                     escreva("Valor a ser pago: ", p, "R$")
                      escreval("")
                      
               outrocaso
                 escreva("Código inserido não foi encontrado!!!")
                  escreval("")
                  
          fimescolha
          


fimalgoritmo