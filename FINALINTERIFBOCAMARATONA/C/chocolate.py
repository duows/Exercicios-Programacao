from decimal import Decimal, getcontext


getcontext().prec = 50  

a_str, b_str, c_str = input().split()

a = int(a_str)
b = Decimal(b_str)
c = Decimal(c_str)

if a == 0:
    print(0)
else:
    if c == 0:
        print(1)
    else:
        total = (b // c)   # quantas barras podem ser compradas (divisão inteira exata)
        res = total // a   # divisão justa
        print(res)
