from typing import *


class Solution:
    def trap(self, height: List[int]) -> int:
        volume = 0
        stack = []

        for i in range(len(height)):
            # 스택을 내림차순으로 관리.
            # 스택에서 pop한다는 것은 오른쪽에 더 큰 값을 찾았다는 의미.
            while stack and height[i] > height[stack[-1]]:
                top = stack.pop()

                # 스택이 비어있지 않으면, 왼쪽에 큰 값이 있음이 보장된다
                if not stack:
                    break

                # 양쪽에 해당 위치보다 더 높은 벽이 있으므로, 왼쪽 벽부터 오른쪽 벽 사이를 빗물로 채울 수 있다.
                distance = i - stack[-1] - 1
                waters = min(height[i], height[stack[-1]]) - height[top]
                volume += distance * waters

            stack.append(i)

        return volume


s = Solution()
print(s.trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]))
