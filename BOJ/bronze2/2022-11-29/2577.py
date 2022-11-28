a = int(input())
b = int(input())
c = int(input())
cnt = [0] * 10
for digit in str(a * b * c):
    cnt[ord(digit) - 48] += 1
print(*cnt, sep='\n')
