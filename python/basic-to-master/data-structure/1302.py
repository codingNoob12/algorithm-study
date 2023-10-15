# # sol 1)
# N = int(input())
# cntDict = {}
# for _ in range(N):
#     book = input()
#     if cntDict.get(book):
#         cntDict[book] += 1
#     else:
#         cntDict[book] = 1
# candidates = [key for key, value in cntDict.items() if value == max(cntDict.values())]
# candidates.sort()
# print(candidates[0])

# sol 2)
d = dict()
for _ in range(int(input())):
    book = input()
    if book in d:
        d[book] += 1
    else:
        d[book] = 1

m = max(d.values())
candi = []
for k, v in d.items():
    if v == m:
        candi.append(k)

candi.sort()
print(candi[0])
