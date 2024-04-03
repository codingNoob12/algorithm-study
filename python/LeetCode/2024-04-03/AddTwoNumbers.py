from typing import *


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        def add_two_node(node1: ListNode, node2: ListNode, carry=0):
            if not node1 and not node2:
                if carry:
                    return ListNode(carry)
                return None

            if not node1:
                result = node2.val + carry
                next = add_two_node(None, node2.next, result // 10)
                return ListNode(result % 10, next)

            if not node2:
                result = node1.val + carry
                next = add_two_node(node1.next, None, result // 10)
                return ListNode(result % 10, next)

            result = node1.val + node2.val + carry
            next = add_two_node(node1.next, node2.next, result // 10)
            return ListNode(result % 10, next)

        return add_two_node(l1, l2)
