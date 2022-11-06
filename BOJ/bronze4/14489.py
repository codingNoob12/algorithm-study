a, b = map(int, input().split())
c = int(input())
bal = a + b
if bal >= 2 * c:
    bal -= 2 * c
print(bal)
