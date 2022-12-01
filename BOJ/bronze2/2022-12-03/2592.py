scores = []
scoreDict = {}
for _ in range(10):
    score = int(input())
    scores.append(score)
    key = str(score)
    if key in scoreDict.keys():
        scoreDict[key] += 1
    else:
        scoreDict[key] = 1
maxCnt = max(scoreDict.values())
print(sum(scores) // 10)
for k, v in scoreDict.items():
    if v == maxCnt:
        print(k)
        break
