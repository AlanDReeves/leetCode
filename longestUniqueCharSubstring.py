class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0
        if len(s) == 1:
            return 1
        maxLength = 0
        for i in range(len(s)):
            for j in range(i + 1, len(s) + 1):
                seen = set()
                checkString = s[i:j]
                duplicateFound = False
                for char in checkString:
                    if char in seen:
                        duplicateFound = True
                        break
                    seen.add(char)
                if duplicateFound:
                    break
                checkLength = len(checkString)
                maxLength = max(maxLength, checkLength)
        return maxLength