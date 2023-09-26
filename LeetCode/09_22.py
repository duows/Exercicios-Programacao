s = input()
t = input()

'''
s = a b c

se i == len(s)
    true

t = a h b g d c

'''

i, j = 0, 0

while i < len(s) and j < len(t):
    if s[i] == t[j]:
        i += 1
    j += 1

if i == len(s):
    print("true")
else:
    print("false")