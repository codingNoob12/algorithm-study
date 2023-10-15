a = int(input())
b = int(input())
c = int(input())
d = int(input())
e = int(input())
t = 0

if a < 0:
    t += -a * c
    a = 0
if a == 0:
    t += d
t += (b - a) * e
print(t)
