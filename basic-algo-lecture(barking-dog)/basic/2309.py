heights = [int(input()) for _ in range(9)]
for i in range(9):
    for j in range(i+1, 9):
        totHeight = 0
        for idx in range(9):
            if idx in (i, j):
                continue
            totHeight += heights[idx]
        if totHeight == 100:
            toDel = (heights[i], heights[j])
            for v in toDel:
                heights.remove(v)
            heights.sort()
            print(*heights, sep='\n')
            exit(0)
