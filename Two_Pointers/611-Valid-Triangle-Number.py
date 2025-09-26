# TRANSLATE COMMENTS TO YOUR LANGUAGE FOR BETTER UNDESTANDING OF THE CODE

def triangleNumber(nums):
    nums.sort() #ordenamos lista
    contador = 0  #metemos los triangulos nuevos

    for k in range(len(nums) - 1, -1, -1):  #que recorra desde el final hasta el inicio de la lista
        lado_largo = nums[k]

        i = 0                            #dos punteros
        j = k - 1                           # este es que j no depende de i sino que j empieza un digito antes de k

        while i < j:
            lado_a = nums[i]                  #sin i es menor a j le asignamos lados en la lista
            lado_b = nums[j]

            if lado_a + lado_b > lado_largo:
                contador += (j - i)  #corregimos porque quiero acumularlos y guardarlos pero con contador
                j -= 1  #probamos un lado mas corto
            else:
                i += 1  #y movemos i de uno en uno

    return contador   #regresamos los lados que metimos dentro del contador
