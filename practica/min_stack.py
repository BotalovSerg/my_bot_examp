
class MinStack:
    def __init__(self) -> None:
        self.main_stack = []
        self.min_stack = []
    
    def push(self, n):
        if len(self.main_stack) == 0:
            self.min_stack.append(n)
        elif n <= self.min_stack[-1]:
            self.min_stack.append(n)
        else:
            self.min_stack.append(self.min_stack[-1])
        self.main_stack.append(n)
    
    def pop(self):
        self.min_stack.pop()
        return self.main_stack()
    
    def get_min(self):
        return self.min_stack[-1]