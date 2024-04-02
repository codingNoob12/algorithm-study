from typing import *


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        rev: Optional[ListNode] = None
        slow: Optional[ListNode] = head
        fast: Optional[ListNode] = head

        # 빠른 러너와 느린 러너로 연결 리스트의 절반을 역순으로 바꿈
        while fast and fast.next:
            fast = fast.next.next
            rev, rev.next, slow = slow, rev, slow.next
        # 만약, 빠른 러너가 끝까지 이동하지 못했으면 fast.next가 None이라서 그런 것
        # 이는 노드의 갯수가 홀수개이고, 느린 러너는 가운데 노드에 있다는 것을 의미함.
        # 이 때, 가운데 노드는 짝이 없으므로 느린 러너를 이동시켜 다음 값부터 비교하게 함
        if fast:
            slow = slow.next

        # 느린 러너와 역순 리스트를 순휘하면서 값이 같은지 확인 [팰린드롬 여부 확인]
        while rev and rev.val == slow.val:
            rev, slow = rev.next, slow.next
        return not rev


nums = [1, 2, 2, 1]
head = None
for i in range(len(nums) - 1, -1, -1):
    head = ListNode(nums[i], head)

s = Solution()
print(s.isPalindrome(head))
