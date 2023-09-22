from math import trunc

n = int(input())
notas = []

for i in range(n):
    f = int(input())
    notas.append(f)

notas.sort(reverse=True)

v = int(input())
qntd = 0

for i in range(len(notas)):
    qntd += v // notas[i]
    v %= notas[i]

print(qntd)
