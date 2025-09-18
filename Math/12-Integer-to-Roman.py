class Solution(object):
    def intToRoman(self, num):
        numeros_romanos = [(1000, "M"), (900, "CM"), (500, "D"), (400, "CD"), (100, "C"), (90, "XC"), (50, "L"), (40, "XL"), (10, "X"), (9, "IX"), (5, "V"), (4, "IV"), (1, "I")] #make the list with all roman

        resultado = []  

        for valor, simbolo in numeros_romanos:
            while num >= valor: # while the number allow to use the valor
                resultado.append(simbolo)
                num -= valor  #rest the valie after append the simbol to result

        return "".join(resultado) #concatenate all the elements in on string
