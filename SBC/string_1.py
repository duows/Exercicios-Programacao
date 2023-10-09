sub = [1, 0]

s = '1001101110'
qtd = 0
index = 0

for num in map(int, s):
    index ^= num
    qtd += sub[index ^ 1]
    sub[index] += 1

print(qtd)
