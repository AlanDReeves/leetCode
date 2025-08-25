class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        lastIndex = -1
        openers = {'(', '{', '['}
        # add forward parenthases to stack until there aren't any
        # for each backwards parenthase, check if the top of the stack matches
        # if so, pop the match off and continue
        # if all values seen and nothing left in stack, return true
        # else return false

        for char in s:
            if char in openers:
                stack.append(char)
                lastIndex += 1
            else: # char in closers
                if lastIndex < 0: #if no openers remaining in stack
                    return False  # return before out of bounds error
                tryMatchChar = stack[lastIndex]
                if tryMatchChar == '(' and char == ')' or tryMatchChar == '{' and char == '}' or tryMatchChar == '[' and char == ']':
                    stack.pop()
                    lastIndex -= 1
                    # valid
                else:
                    return False
        if len(stack) > 0: # if there are leftover openers when the loop is done
            return False
        return True