# # sol 1)
# import sys
# input = sys.stdin.readline
# numDict = {}
# for _ in range(int(input())):
#     num = int(input())
#     if num in numDict.keys():
#         numDict[num] += 1
#     else:
#         numDict[num] = 1
# for k in sorted(numDict.keys()):
#     for _ in range(numDict[k]):
#         print(k)

import sys
input = sys.stdin.buffer.readline
counts = [0 for i in range(10010)]
for n in range(int(input())):
    counts[int(input())] += 1
for i in range(10010):
    for j in range(counts[i]):
        sys.stdout.write(str(i)+"\n")
