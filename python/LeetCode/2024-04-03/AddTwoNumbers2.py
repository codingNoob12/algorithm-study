from typing import *
from functools import *


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        a = self.toList(self.reverseList(l1))
        b = self.toList(self.reverseList(l2))

        num1 = reduce(lambda x, y: 10 * x + y, a, 0)
        num2 = reduce(lambda x, y: 10 * x + y, b, 0)

        result = num1 + num2
        return self.toReversedLinkedList(str(result))

    def reverseList(self, head: ListNode) -> ListNode:
        node, prev = head, None

        while node:
            next, node.next = node.next, prev
            node, prev = next, node

        return prev

    def toList(self, node: ListNode) -> List:
        list: List = []
        while node:
            list.append(node.val)
            node = node.next
        return list

    def toReversedLinkedList(self, result: str) -> ListNode:
        node = None
        for digit in result:
            node = ListNode(int(digit), node)
        return node
