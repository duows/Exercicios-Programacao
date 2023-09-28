'''
se poured == 0
    retorna 0
fim se

anterior recebe total colocado(poured)

enquanto query_row > 0
    "(anterior[0] - 1) / 2 -> total de champagne menos a primeira taça"
    pos recebe (anterior[0] - 1) / 2
    atual = [pos]

    faça i enquanto i < anterior

'''

def champagne_tower(poured , query_row , query_glass ):
    if poured == 0:
        return 0

    anterior = [float(poured)]

    while query_row > 0:
        pos = (anterior[0] - 1) / 2
        atual = [pos]

        for i in range(1, len(anterior)):
            esq = max(0, (anterior[i - 1] - 1) / 2)
            dir = max(0, (anterior[i] - 1) / 2)
            atual.append(esq + dir)

        atual.append(pos)
        anterior = atual
        query_row -= 1

    return min(1, anterior[query_glass])

poured = 25
query_row = 6
query_glass = 1
resultado = champagne_tower(poured, query_row, query_glass)
print(resultado)