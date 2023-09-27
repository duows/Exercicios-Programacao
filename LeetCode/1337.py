total = []

for i, row in enumerate(mat):
    cont = 0
    for element in row:
        if element == 1:
            cont += 1
    total.append((cont, i))

sorted_result = sorted(total, reverse=False, key=lambda x: x[0])

indices_to_print = [item[1] for item in sorted_result[:k]]

print(indices_to_print)