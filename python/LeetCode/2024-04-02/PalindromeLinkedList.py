from typing import *


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        p: List = []

        if not head:
            return True

        node = head
        while node is not None:
            p.append(node.val)
            node = node.next

        return p == p[::-1]


nums = [1, 2, 2, 1]
head = None
for i in range(len(nums) - 1, -1, -1):
    head = ListNode(nums[i], head)

s = Solution()
print(s.isPalindrome(head))
