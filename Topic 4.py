print('Topic 4')
class SkincareStack:
    def __init__(self, max_size):
        self.stack = []
        self.max_size = max_size

    def push(self, order):
        if len(self.stack) < self.max_size:
            self.stack.append(order)
        else:
            print("Stack is full!")

    def pop(self):
        if self.stack:
            return self.stack.pop()
        else:
            print("Stack is empty!")

    def display(self):
        print("Stack:", self.stack)

# Example usage
ss = SkincareStack(3)
ss.push("Order 1 for hand creamm")
ss.push("Order 2 for cleanser")
ss.push("Order 3 for sunscreen")
ss.display()
ss.pop()
ss.display()
