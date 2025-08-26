Algoritmo "Conversor_real"

  var
  
    A : real
    b : real
    c : real
    
      inicio
      
        Escreval("Insira a cotação do dolar:")
        leia(A)
        
        escreval("Insira o valor em real a ser convertido:")
        leia(B)
        
        se A = 0 então
        escreva("valor invalido")
        senão
        C := B/A
        escreva("Valor convertido:" , C)
        fimse

fimalgoritmo