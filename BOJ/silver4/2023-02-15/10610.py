# 3의 배수 : 모든 자리의 수의 합이 3의 배수
# 10의 배수 : 일의 자리 0
n = input()
digits = sorted([int(digit) for digit in n], reverse=True)
if sum(digits) % 3 == 0 and digits[-1] == 0:
    print(*digits, sep="")
else:
    print(-1)
