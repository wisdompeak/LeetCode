from collections import Counter


class Solution(object):
    def findEvenNumbers(self, digits):
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
                        numero = d1*100 + d2*10 + d3
                        result.append(numero)

            return sorted(result)
