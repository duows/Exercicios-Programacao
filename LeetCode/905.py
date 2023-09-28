nums = [3, 1, 2, 4]

newNums = []

for cont in range(len(nums) - 1, -1, -1):
    if (nums[cont] % 2) == 0:
        print(nums[cont])
        newNums.append(nums[cont])
        nums.pop(cont)

newNums += nums

print(newNums)

'''
class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        nums[:] = [i for i in nums if i%2==0] + [j for j in nums if j%2!=0]
        return nums

a solução funciona filtrando números pares e ímpares da matriz de entrada usando 
compreensões de lista e concatenando-os na ordem desejada. Esta abordagem é eficiente e 
reorganiza os elementos do array conforme necessário para atender às especificações do problema.
'''