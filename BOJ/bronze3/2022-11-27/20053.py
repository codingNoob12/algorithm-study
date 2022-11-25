t = int(input())
for _ in range(t):
    n = int(input())
    nums = list(map(int, input().split()))
    print(min(nums), max(nums))

# 최적화하려면 한 루프에 최대와 최소를 구하게 만들면 된다.
# 지금은 각각 루프돌아서 최대, 최소를 구한 것
