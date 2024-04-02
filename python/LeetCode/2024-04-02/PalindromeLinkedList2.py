from typing import *
from collections import deque


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        p: Deque = deque()

        if not head:
            return True

        node = head
        while node is not None:
            p.append(node.val)
            node = node.next

        while len(p) > 1:
            if p.pop() != p.popleft():
                return False

        return True


nums = [1, 2, 2, 1]
head = None
for i in range(len(nums) - 1, -1, -1):
    head = ListNode(nums[i], head)

s = Solution()
print(s.isPalindrome(head))
