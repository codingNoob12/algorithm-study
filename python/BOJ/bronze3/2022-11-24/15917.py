# from sys import stdin
# chkList = [2 ** i for i in range(32)]
# q = int(input())
# for _ in range(q):
#     a = int(stdin.readline().strip())
#     if a in chkList:
#         print(1)
#     else:
#         print(0)

from sys import stdin
q = int(input())
for _ in range(q):
    a = int(stdin.readline().strip())
    if (a & (-a)) == a:
        print(1)
    else:
        print(0)
