n = int(input())
gen = 0
for i in range(1, n):
    divSum = i
    for ch in str(i):
        divSum += int(ch)
    if divSum == n:
        gen = i
        break
print(gen)
