tList = [i * (i + 1) // 2 for i in range(1, 100)]
def isEureka(n):
    for i in range(len(tList)):
        for j in range(len(tList)):
            for k in range(len(tList)):
                if tList[i] + tList[j] + tList[k] == n:
                    return True
    return False

for _ in range(int(input())):
    if isEureka(int(input())):
        print(1)
    else:
        print(0)
