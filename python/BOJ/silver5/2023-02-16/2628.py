# w, h = map(int, input().split())
# cutList = [[] for _ in range(2)]
# for _ in range(int(input())):
#     t, line = map(int, input().split())
#     cutList[t].append(line)
#
# for i in range(2):
#     cutList[i].append(0)
#     cutList[i].append(h if i == 0 else w)
#
# for i in range(2):
#     cutList[i].sort()
#
# r = max([cutList[0][i] - cutList[0][i - 1] for i in range(1, len(cutList[0]))])
# c = max([cutList[1][i] - cutList[1][i - 1] for i in range(1, len(cutList[1]))])
#
# print(r * c)

width, height = map(int, input().split())
cuts = {0: [], 1: []}

for _ in range(int(input())):
    direction, position = map(int, input().split())
    cuts[direction].append(position)

for cut in cuts.values():
    cut.extend([0, height if cut is cuts[0] else width])
    cut.sort()

row_length = max(cuts[0][i] - cuts[0][i - 1] for i in range(1, len(cuts[0])))
col_length = max(cuts[1][i] - cuts[1][i - 1] for i in range(1, len(cuts[1])))

print(row_length * col_length)
