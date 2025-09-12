from collections import Counter


def findEvenNumbers(digits):
    result = []
    digit_count = Counter(digits)

    for d1 in digit_count:
        if d1 == 0:
            continue
        rest1 = digit_count.copy()
        rest1[d1] -= 1

        for d2 in rest1:
            if rest1[d2] == 0:
                continue
            rest2 = rest1.copy()
            rest2[d2] -= 1

            for d3 in rest2:
                if rest2[d3] == 0:
                    continue
                if d3 % 2 != 0:
                    continue
                numero = d1 * 100 + d2 * 10 + d3
                result.append(numero)

    return sorted(result)


digits = [2, 1, 3, 0]
print(findEvenNumbers(digits))

digits = [2, 1, 3, 0]
print(findEvenNumbers(digits))

# This Code below is only for testing, please guide by code above but just in case
# is needed try to use as guide this code for solucion as O(n) and not O(N3)
    
# for combo in permutations(digits, 3):
#     a,b,c = combo
#     if a == 0 or c % 2 != 0:
#         continue
#
#     conteo = Counter(combo)
#     if all(conteo[d] <= digit_count[d] for d in conteo):
#         numero = a*100 + b*10 + c
#         result.add(numero)

# for primer_digito in digits:
#     if primer_digito == 0:
#         continue
# for segundo_digito in digits:
#     for tercer_digito in digits:
#         if tercer_digito % 2 != 0:
#             continue
#
#         conteo = Counter([primer_digito, segundo_digito, tercer_digito])
#         valido = all(conteo[d] <= digit_count[d] for d in conteo)
#
#         if valido:
#             numero = primer_digito*100 + segundo_digito*100 + tercer_digito
#             result.append(numero)

# # quitar duplicados y ordenar
# result = sorted(set(result))
# return result
