def isRes(n):
    tmp = str(n)
    if len(tmp) == tmp.count('4') + tmp.count('7'):
        return True
    return False

for i in range(int(input()), 0, -1):
    if isRes(i):
        print(i)
        break
