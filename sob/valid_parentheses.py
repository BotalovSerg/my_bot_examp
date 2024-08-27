class Solution:
    def __init__(self):
        self.stack = []
        self.chars = {"}": "{", "]": "[", ")": "("}

    def isValid(self, s: str) -> bool:
        for char in s:
            if self.is_empty() and char in [")", "}", "]"]:
                return False
            if char in ["(", "{", "["]:
                self.stack.append(char)
            elif char in [")", "}", "]"] and self.stack[-1] == self.chars[char]:
                self.stack.pop()
            else:
                return False

        return self.is_empty()

    def is_empty(self):
        return len(self.stack) == 0


solution = Solution()
s = "(])"
print(solution.isValid(s))