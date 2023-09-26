class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        sLower = s.lower()
        sNoRepetition = ""
        
        for i in sLower:
            if i not in sNoRepetition:
                sNoRepetition += i

        

        return sSaida

