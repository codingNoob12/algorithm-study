n, k = map(int, input().split())
outlets = list(map(int, input().split()))
available = 0
for outlet in outlets:
    available += (outlet + 1) // 2
if available < n:
    print('NO')
else:
    print('YES')
