from typing import *


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head

        p: ListNode = head
        q: ListNode = head.next
        root = node = ListNode(0)

        while p and q:
            node.next = ListNode(q.val)
            node = node.next
            node.next = ListNode(p.val)
            node = node.next

            if p.next:
                p = p.next.next
            if q.next:
                q = q.next.next

        if p:
            node.next = ListNode(p.val)

        return root.next
