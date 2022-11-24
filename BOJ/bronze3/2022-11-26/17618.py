# 시간복잡도는 O(n)이지만 n이 10,000,000까지 들어와서 python3로는 시간초과가 남
# PyPy3에서는 통과 가능
## Python3에서는 1초에 100,000까지는 넉넉히 처리가능. 1,000,000은 간신히 통과할 수도 있다
## PyPy3에서는 1초에 1,000,000까지는 넉넉히 처리가능. 10,000,000은 간신히 통과할 수도 있다.
n = int(input())
cnt = 0
for i in range(1, n+1):
    eachSum = 0
    for digit in str(i):
        eachSum += int(digit)
    if i % eachSum == 0:
        cnt += 1
print(cnt)
