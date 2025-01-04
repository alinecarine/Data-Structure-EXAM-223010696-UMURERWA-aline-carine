# topic three
print ('TOPIC 3')
from collections import deque

class SkincareDeque:
    def __init__(self):
        self.deque = deque()

    def add_to_front(self, product):
        self.deque.appendleft(product)

    def add_to_rear(self, product):
        self.deque.append(product)

    def remove_from_front(self):
        return self.deque.popleft()

    def remove_from_rear(self):
        return self.deque.pop()

    def display(self):
        print("Deque:", list(self.deque))

# Example usage
sd = SkincareDeque()
sd.add_to_rear("cleanser")
sd.add_to_rear("sunscreen")
sd.add_to_front("hand cream")
sd.display()
sd.remove_from_front()
sd.display()
