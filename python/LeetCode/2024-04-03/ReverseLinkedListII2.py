from typing import *


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next: ListNode = next


class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        root = node = ListNode(None)
        root.next = head

        prev_left = root
        for _ in range(left):
            node, prev_left = node.next, node

        node, prev = node.next, node
        for _ in range(right - left):
            next, node.next = node.next, prev
            node, prev = next, node

        prev_left.next.next, prev_left.next = node, prev

        return root.next
