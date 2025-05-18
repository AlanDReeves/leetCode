class Solution:
    def myAtoi(self, s: str) -> int:
        total = 0
        isNegative = False
        digitsStarted = False
        signSeen = False
        for char in s:
            if char.isalpha():
                break
            if char == "." or char ==",":
                break
            if char.isspace() and not digitsStarted:
                if signSeen:
                    break
                continue
            if char == "-" and not digitsStarted:
                if signSeen:
                    break
                isNegative = True
                signSeen = True
            if char == "+" and not digitsStarted:
                if signSeen:
                    break
                signSeen = True
                continue
            if char.isdigit():
                digitsStarted = True
                total *= 10
                total += int(char)
            if digitsStarted and not char.isdigit():
                break
        if isNegative:
            total *= -1
        if total < (-2 ** 31):
            return (-2 ** 31)
        if total > (2 ** 31) - 1:
            return (2 ** 31) - 1
        return total
    