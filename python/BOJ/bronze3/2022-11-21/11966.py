n = int(input())
chkList = [2 ** i for i in range(31)]
if n in chkList:
    print(1)
else:
    print(0)
