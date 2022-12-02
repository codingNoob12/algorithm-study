# i번째에서 오큰수를 보면 기준이 불명확 => 관점을 달리하기.. (n이 100만... => 시간복잡도 N으로 처리)
# stack
# [3]
# [5]
# [5, 2]
# [7]
# pop할 때, 비교하는 거를 res에 append하면 될듯?
n = int(input())
nums = list(map(int, input().split()))
stk, res = [], [-1] * n
for i, num in enumerate(nums):
    while stk and stk[-1][1] < num:
        res[stk[-1][0]] = num
        stk.pop()
    stk.append((i, num))
print(*res)
# 스택은 도대체 언제 쓰는 거지..? 최적화할 때..? 검색 최소화 같이..
# 아마 최근 거랑 비교할 수 있으면 stack쓰는게 빠른듯... 검색 시간 단축되니까
