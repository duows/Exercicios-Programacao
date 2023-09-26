s = input()
t = input()

diferenca = ""

for char in t:
    if (char not in s or t.count(char) > s.count(char)) and char not in diferenca:
        diferenca += char

print(diferenca)

'''
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        return chr(sum(ord(char) for char in t) - sum(ord(char) for char in s))

ALGORITMO MUITCHO DOIDO Q EU ACHEI N SEI COMO FUNCIONA

'''