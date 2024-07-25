import sys
input = sys.stdin.read

def main():
    data = input().strip().split()
    index = 0

    N = int(data[index])
    index += 1
    M = int(data[index])
    index += 1
    L = int(data[index])
    index += 1

    fluxos = []
    
    # Lê os valores e separa nos respectivos vetores de fluxo
    for i in range(N):
        fluxo = []
        for j in range(L):
            valor = int(data[index])
            index += 1
            fluxo.append(valor)
        fluxos.append(fluxo)

    quadroAtual = 1
    
    for posInicial in range(0, L, M):
        somaQuadro = 0

        for i in range(N):
            for j in range(M):
                pos = posInicial + j
                if pos < L:
                    print(fluxos[i][pos])
                    somaQuadro += fluxos[i][pos]

        mod = somaQuadro % 256
        print(mod)

        quadroAtual += 1

if __name__ == "__main__":
    main()
