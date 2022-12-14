from collections import deque
for _ in range(int(input())):
    n, m = map(int, input().split())
    importance = list(map(int, input().split()))
    items = deque(list(enumerate(importance)))
    importance.sort()
    cnt = 0
    while items:
        item = items.popleft()
        for i in importance:
            if item[1] < i:
                items.append(item)
                break
        else:
            importance.pop()
            cnt += 1
            if item[0] == m:
                break
    print(cnt)
