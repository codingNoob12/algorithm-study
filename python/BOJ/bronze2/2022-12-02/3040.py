dwarfs = []
for _ in range(9):
    dwarfs.append(int(input()))
for i in range(9):
    for j in range(i+1, 9):
        sumVal = 0
        for idx in range(9):
            if idx in (i, j):
                continue
            sumVal += dwarfs[idx]
        if sumVal == 100:
            dwarfs.pop(j)
            dwarfs.pop(i)
            print(*dwarfs, sep='\n')
            exit(0)
