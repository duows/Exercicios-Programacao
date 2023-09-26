def removeDuplicateLetters(s):
    last_occurrence = {char: idx for idx, char in enumerate(s)}
    stack = []
    visitado = set()
    
    for idx, char in enumerate(s):
        if char in visitado:
            continue
        
        while stack and char < stack[-1] and idx < last_occurrence[stack[-1]]:
            visitado.remove(stack.pop())
        
        stack.append(char)
        visitado.add(char)
    
    return ''.join(stack)

s = input()
result = removeDuplicateLetters(s)
print(result)