n, m = map(int, input().split())
apples = [int(input()) for _ in range(int(input()))]

pos, cnt = 1, 0
for apple in apples:
    while apple not in range(pos, pos + m):
        if pos < apple:
            pos += 1
        else:
            pos -= 1
        cnt += 1
print(cnt)
