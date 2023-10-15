L = int(input())
st = input()
r, M = 31, 1234567891
H = 0
for i in range(len(st)):
    H += (ord(st[i]) - 96) * (r ** i)
print(H % M)
