from typing import *


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next: ListNode = next


class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        merged_list = []
        for list in lists:
            merged_list += self.toList(list)
        merged_list.sort()
        return self.toLinkedList(merged_list)

    def toList(self, head: Optional[ListNode]) -> List[int]:
        result = []
        while head:
            result.append(head.val)
            head = head.next
        return result

    def toLinkedList(self, list: List[int]) -> Optional[ListNode]:
        root = p = ListNode()
        for value in list:
            node = ListNode(value)
            p.next = node
            p = p.next
        return root.next
