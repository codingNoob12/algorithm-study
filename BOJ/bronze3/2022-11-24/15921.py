n = int(input())
if n == 0:
    print('divide by zero')
    exit(0)
records = list(map(int, input().split()))
if sum(records) == 0:
    print('divide by zero')
else:
    # 평균 == 균일한 확률에서의 기댓값
    print('1.00')
