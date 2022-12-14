import math
cnt = 0
for digit in str(math.factorial(int(input())))[::-1]:
    if digit != '0':
        break
    cnt += 1
print(cnt)
