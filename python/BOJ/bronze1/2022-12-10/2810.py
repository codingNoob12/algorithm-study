n = int(input())
seats = input()
hanger = len(seats) + 1 - seats.count('L') // 2
print(n if hanger > n else hanger)
