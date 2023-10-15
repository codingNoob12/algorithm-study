radixA, radixB = map(int, input().split())
m = int(input())
A = list(map(int, input().split()))
decimalA = 0
for i, digit in enumerate(A[::-1]):
    decimalA += digit * radixA ** i
B = []
while decimalA:
    B.append(decimalA % radixB)
    decimalA //= radixB
print(*B[::-1])
