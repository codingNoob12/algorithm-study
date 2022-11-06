l = int(input())
a = int(input())
b = int(input())
c = int(input())
d = int(input())

kor = a // c
if a % c != 0:
    kor += 1
mat = b // d
if b % d != 0:
    mat += 1
free = l - max(kor, mat)
print(free)
