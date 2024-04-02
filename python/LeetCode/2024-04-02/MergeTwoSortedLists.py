from typing import *


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if list1 is None:
            return list2

        if list2 is None:
            return list1

        head = None
        p, q, r = list1, list2, None

        while p and q:
            if p.val < q.val:
                node = ListNode(p.val)
                p = p.next
            else:
                node = ListNode(q.val)
                q = q.next

            if r is None:
                head, r = node, node
            else:
                r.next = node
                r = r.next

        while p:
            r.next, p = p, p.next
            r = r.next

        while q:
            r.next, q = q, q.next
            r = r.next

        return head


nums1 = [1, 2, 4]
nums2 = [1, 3, 4]
head1, head2 = None, None
for i in range(len(nums1) - 1, -1, -1):
    head1 = ListNode(nums1[i], head1)
for i in range(len(nums2) - 1, -1, -1):
    head2 = ListNode(nums2[i], head2)

s = Solution()
s.mergeTwoLists(head1, head2)
