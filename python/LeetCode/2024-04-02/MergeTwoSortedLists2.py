from typing import *


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        if (not l1) or (l2 and l1.val > l2.val):
            l1, l2 = l2, l1
        if l1:
            l1.next = self.mergeTwoLists(l1.next, l2)
        return l1


nums1 = [-9, 3]
nums2 = [5, 7]

head1, head2 = None, None
for i in range(len(nums1) - 1, -1, -1):
    head1 = ListNode(nums1[i], head1)
for i in range(len(nums2) - 1, -1, -1):
    head2 = ListNode(nums2[i], head2)

s = Solution()
result = s.mergeTwoLists(head1, head2)
while result:
    print(result.val)
    result = result.next
