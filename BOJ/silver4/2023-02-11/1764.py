import sys
input = sys.stdin.readline
N, M = map(int, input().rstrip().split())
nameDict = {}
for _ in range(N + M):
    name = input().rstrip()
    if name in nameDict.keys():
        nameDict[name] += 1
    else:
        nameDict[name] = 1
ans = []
for name, cnt in nameDict.items():
    if cnt == 2:
        ans.append(name)
ans.sort()
print(len(ans), *ans, sep='\n')
