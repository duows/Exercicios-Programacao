s = "leet2code3"
k = 10

tamanhoString = 0
cont = 0
s2 = ""

while tamanhoString < k:
    if s[cont].isnumeric():
        tamanhoString *= int(s[cont])
    else:
        tamanhoString += 1
    cont += 1

for cont in range(cont-1, -1, -1):
    c = s[cont]
    if c.isdigit():
        tamanhoString //= int(c)
        k %= tamanhoString
    else:
        if k == 0 or k == tamanhoString:
            print(c)
            break
        tamanhoString -= 1