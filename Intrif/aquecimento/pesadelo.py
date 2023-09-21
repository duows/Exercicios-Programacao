from decimal import Decimal, getcontext
import math

# Definir a precisão decimal desejada (12 casas decimais)
getcontext().prec = 14  # Ajuste para 14 para garantir 12 casas decimais após a vírgula

PI = Decimal('3.14159265358979323846')

r = int(input())

if r < 1 or r > 100:
    exit()

azinho = Decimal('36.869897645')
theta = Decimal('73.739795266608263933829256231553122024909673218277166042005784900')

theta = round(theta, 12)

alpha = Decimal(r) / Decimal('2.0')
x = Decimal(r) * Decimal('2.0')
y = Decimal('5.0') * alpha
z = Decimal('3.0') * alpha

ab = x**2 / y
h = (r**2 - ab**2 / Decimal('4.0')).sqrt()

a1 = (ab * h) / Decimal('2.0')
a2 = (theta * PI * (r**2)) / Decimal('360.0')

areaTotal = a1 + a2

