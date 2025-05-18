class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s) < 2:
            return s
        
        start = 0
        longest = 1

        for i in range(len(s)):
            # odd palindrome check
            l, r = i, i
            while  l >= 0 and r < len(s) and s[l] == s[r]:
                if r - l + 1 > longest:
                    start = l
                    longest = r - l + 1
                l -= 1
                r += 1
            
            # even palindrome check
            l = i
            r = i + 1
            while l >= 0 and r < len(s) and s[l] == s[r]:
                if r - l + 1 > longest:
                    start = l
                    longest = r - l + 1
                l -= 1
                r += 1

        return s[start: start + longest]