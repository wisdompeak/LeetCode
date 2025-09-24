
class Solution:
    def reverse(self, x: int) -> int:
        if x < 0:
            signo = -1
        else:
            signo = 1
        x = abs(x)

        resultado = 0

        while x > 0:
            digito = x % 10  #last digit of x
            resultado = (resultado * 10 + digito) #add digit to resultado
            x = x // 10
        resultado = resultado * signo

        if resultado < -2_147_483_648 or resultado > 2_147_483_647:
            return 0
        else:
            return resultado
