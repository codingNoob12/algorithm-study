from typing import *


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next: ListNode = next


class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        odd_root = odd_node = ListNode(None)
        even_root = even_node = ListNode(None)
        p, count = head, 1
        while p:
            if count % 2:
                odd_node.next = p
                odd_node = odd_node.next
            else:
                even_node.next = p
                even_node = even_node.next
            p = p.next
            count += 1
        even_node.next = None
        odd_node.next = even_root.next
        return odd_root.next
