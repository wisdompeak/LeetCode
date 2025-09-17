class Solution(object):
    def minimumTeachings(self, n, languages, friendships):
        usuarios_problematicos = set()

        for a, b in friendships:
            if set(languages[a -1]).isdisjoint(set(languages[b-1])):
                usuarios_problematicos.add(a)
                usuarios_problematicos.add(b)

        respuesta = float('inf')

        for idioma_b in range(1, n + 1):
            contador = 0

            for u in usuarios_problematicos:
                if idioma_b not in languages[u - 1]:
                    contador += 1

            respuesta = min(respuesta, contador)

        return respuesta
