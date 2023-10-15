def label(pos: tuple, group_number):
    x, y = pos
    if x < 0 or x >= len(square) or y < 0 or y >= len(square):
        return
    if square[x][y] == 1:
        square[x][y] = group_number
        if group_number not in group_numbers:
            group_numbers.append(group_number)
        for dx, dy in dA:
            label((x + dx, y + dy), group_number)

def count(n):
    cnt = 0
    for i in range(len(square)):
        for j in range(len(square)):
            if square[i][j] == n:
                cnt += 1
    return cnt

square = [list(map(int, input())) for _ in range(int(input()))]
group_numbers = []
dA = [(1, 0), (0, 1), (-1, 0), (0, -1)]

group_number = 2
for i in range(len(square)):
    for j in range(len(square)):
        label((i, j), group_number)
        if group_number in group_numbers:
            group_number += 1
print(len(group_numbers))
counts = sorted(count(group_number) for group_number in group_numbers)
print(*counts, sep='\n')
