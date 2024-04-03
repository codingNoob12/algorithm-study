from typing import *


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next: ListNode = next


class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        node, prev = head, None
        prev_left = None
        for i in range(1, right + 1):
            next = node.next
            if left < i:
                node.next = prev
            else:
                prev_left = prev
            node, prev = next, node
        if prev_left:
            prev_left.next.next = node
            prev_left.next = prev
        else:
            head.next = node
            head = prev

        return head
