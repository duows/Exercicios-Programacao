words = ["a", "b", "ba", "bca", "bda", "bdca"]

cadeia = {}

word = sorted(words, key=len)

for i in word:
    cadeia[i] = 1
    for j in range(len(i)):
        palavra = i[:j] + i[j+1:]
        if palavra in cadeia:
            cadeia[i] = max(cadeia[palavra] + 1, cadeia[i])

print(max(cadeia.values()))
