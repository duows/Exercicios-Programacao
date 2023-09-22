from math import sqrt

def isPrimo(num):
    if num <= 1:
        return False
    for i in range(2, int(sqrt(num)) + 1):
        if num % i == 0:
            return False
    return True

n = int(input())

primos = [str(i) for i in range(2, n + 1) if isPrimo(i)]

resultado = " ".join(primos)
print(resultado)