from typing import *


class ListNode:
    def __init__(self, val=0, left=None, right=None):
        self.val: int = val
        self.left: Optional[ListNode] = left
        self.right: Optional[ListNode] = right


class MyCircularDeque:

    def __init__(self, k: int):
        self.max_size, self.size = k, 0
        self.front = self.rear = ListNode()
        self.front.right, self.front.left = self.front, self.front

    def insertFront(self, value: int) -> bool:
        if self.isFull():
            return False
        node = ListNode(value, self.front, self.front.right)
        self.front.right.left = node
        self.front.right = node
        self.size += 1
        if self.front == self.rear:
            self.rear = node
        return True

    def insertLast(self, value: int) -> bool:
        if self.isFull():
            return False
        node = ListNode(value, self.rear, self.front)
        self.rear.right, self.front.left = node, node
        self.rear = node
        self.size += 1
        return True

    def deleteFront(self) -> bool:
        if self.isEmpty():
            return False
        self.front.right.right.left = self.front
        self.front.right = self.front.right.right
        self.size -= 1
        if self.isEmpty():
            self.rear = self.front
        return True

    def deleteLast(self) -> bool:
        if self.isEmpty():
            return False
        self.front.left = self.rear.left
        self.rear.left.right = self.front
        self.rear = self.rear.left
        self.size -= 1
        return True

    def getFront(self) -> int:
        if self.isEmpty():
            return -1
        return self.front.right.val

    def getRear(self) -> int:
        if self.isEmpty():
            return -1
        return self.rear.val

    def isEmpty(self) -> bool:
        return not self.size

    def isFull(self) -> bool:
        return self.size == self.max_size


obj = MyCircularDeque(8)
print(None)
print(obj.insertFront(5))
print(obj.getFront())
print(obj.isEmpty())
print(obj.deleteFront())
print(obj.insertLast(3))
print(obj.getRear())
print(obj.insertLast(7))
print(obj.insertFront(7))
print(obj.deleteLast())
print(obj.insertLast(4))
print(obj.isEmpty())
