k = int(input())
d1, d2 = map(int, input().split())
width = abs(d1 - d2) / 2
heightSquare = k ** 2 - width ** 2
print(heightSquare)
