for _ in range(int(input())):
    schoolDict = {}
    for _ in range(int(input())):
        s, l = input().split()
        schoolDict[s] = int(l)
    maxL = max(schoolDict.values())
    for k, v in schoolDict.items():
        if v == maxL:
            print(k)
            break
