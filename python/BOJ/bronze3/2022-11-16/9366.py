t = int(input())
for i in range(1, t+1):
    lenList = list(map(int, input().split()))
    lenList.sort()
    a, b, c = lenList
    if a + b <= c:
        res = 'invalid!'
    elif a == b == c:
        res = 'equilateral'
    elif a == b != c or a != b == c:
        res = 'isosceles'
    else:
        res = 'scalene'
    print(f'Case #{i}:', res)
