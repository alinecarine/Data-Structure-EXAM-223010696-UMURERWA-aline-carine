print('Topic 5')
from collections import deque

class SkincareQueue:
    def __init__(self):
        self.queue = deque()

    def enqueue(self, data):
        self.queue.append(data)

    def dequeue(self):
        if self.queue:
            return self.queue.popleft()
        else:
            print("Queue is empty!")

    def display(self):
        print("Queue:", list(self.queue))

# Example usage
sq = SkincareQueue()
sq.enqueue("User 1")
sq.enqueue("User 2")
sq.display()
sq.dequeue()
sq.display()
