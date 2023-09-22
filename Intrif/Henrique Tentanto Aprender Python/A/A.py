nome = input()
qtdeVogais = 0

for c in nome:
    if c in 'aeiouAEIOU':
        qtdeVogais += 1

frasco = qtdeVogais % 3

match frasco:
    case 0:
        print('frasco 0')
    case 1:
        print('frasco 1')
    case 2:
        print('frasco 2')