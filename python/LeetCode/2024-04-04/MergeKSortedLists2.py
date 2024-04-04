from typing import *
import heapq


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next: ListNode = next


class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        root = p = ListNode()
        heap = []

        for i in range(len(lists)):
            if lists[i]:
                heapq.heappush(heap, (lists[i].val, i, lists[i]))

        while heap:
            value, i, node = heapq.heappop(heap)
            p.next = node
            p = p.next

            if p.next:
                heapq.heappush(heap, (p.next.val, i, p.next))

        return root.next
