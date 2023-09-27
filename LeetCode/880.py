class Solution:
    def decodeAtIndex(self, s: str, k: int) -> str:
        cont1 = 0
        s2 = ""

        if k == 1:
            return s[0]
        else:
            while cont1 < len(s):
                if s[cont1].isnumeric():
                    s2 = s2 * int(s[cont1])
                else:
                    s2 += s[cont1]
                cont1 += 1
            
            return s2[k-1]