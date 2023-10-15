import sys

input = sys.stdin.readline
N, M = map(int, input().rstrip().split())
nameList = [input().rstrip() for _ in range(1, N + 1)]
orderDict = {name: i + 1 for i, name in enumerate(nameList)}
for _ in range(M):
    question = input().rstrip()
    if question.isdigit():
        print(nameList[int(question) - 1])
    else:
        print(orderDict[question])
