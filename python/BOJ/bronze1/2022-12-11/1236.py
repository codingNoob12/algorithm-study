size = list(map(int, input().split()))
room = [input() for _ in range(size[0])]
rList, cList = [], []
for r in range(size[0]):
    if 'X' not in room[r]:
        rList.append(r)
for c in range(size[1]):
    if 'X' not in ''.join([room[r][c] for r in range(size[0])]):
        cList.append(c)
print(max(len(rList), len(cList)))
