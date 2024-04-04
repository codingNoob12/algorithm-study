from typing import *


class MyCircularQueue:

    def __init__(self, k: int):
        self.size: int = k + 1
        self.data: List[Optional[int]] = [None] * (k + 1)
        self.front: int = 0
        self.rear: int = 0

    def enQueue(self, value: int) -> bool:
        if self.isFull():
            return False
        self.rear = (self.rear + 1) % self.size
        self.data[self.rear] = value
        return True

    def deQueue(self) -> bool:
        if self.isEmpty():
            return False
        self.front = (self.front + 1) % self.size
        self.data[self.front] = None
        return True

    def Front(self) -> int:
        if self.isEmpty():
            return -1
        return self.data[(self.front + 1) % self.size]

    def Rear(self) -> int:
        if self.isEmpty():
            return -1
        return self.data[self.rear]

    def isEmpty(self) -> bool:
        return self.front == self.rear

    def isFull(self) -> bool:
        return self.front == (self.rear + 1) % self.size
