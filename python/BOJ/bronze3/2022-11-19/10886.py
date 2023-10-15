n = int(input())
cnt = 0
for _ in range(n):
    cnt += int(input())
if cnt > n - cnt:
    print('Junhee is cute!')
else:
    print('Junhee is not cute!')
