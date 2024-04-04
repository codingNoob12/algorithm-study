from typing import *


class ListNode:
    def __init__(self, key=0, val=0, next=None):
        self.key = key
        self.val = val
        self.next = next


class MyHashMap:

    def __init__(self):
        self.hash_table = [ListNode(-1) for _ in range(31)]

    def put(self, key: int, value: int) -> None:
        self.remove(key)
        hash_code = key % 31
        node = self.hash_table[hash_code]
        while node.next:
            node = node.next
        node.next = ListNode(key, value)

    def get(self, key: int) -> int:
        hash_code = key % 31
        node = self.hash_table[hash_code]
        while node:
            if node.key == key:
                return node.val
            node = node.next
        return -1

    def remove(self, key: int) -> None:
        hash_code = key % 31
        node, prev = self.hash_table[hash_code], None
        while node:
            if node.key == key:
                prev.next = node.next
                return
            node, prev = node.next, node


obj = MyHashMap()
print(None)
print(obj.put(1, 1))
print(obj.put(2, 2))
print(obj.get(1))
print(obj.get(3))
print(obj.put(2, 1))
print(obj.get(2))
print(obj.remove(2))
print(obj.get(2))
