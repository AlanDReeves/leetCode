class Solution:
    def isPalindrome(self, x: int) -> bool:
        numString = str(x)
        isEven = False
        if len(numString) % 2 == 0:
            isEven = True
        
        l, r = (len(numString) // 2), (len(numString) // 2)
        if isEven:
            l -= 1
        
        while l >= 0 and r < len(numString):
            if numString[l] != numString[r]:
                return False
            l -= 1
            r += 1
        return True