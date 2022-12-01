from math import sqrt
d, h, w = map(int, input().split())
t = d / sqrt(h ** 2 + w ** 2)
print(int(h * t), int(w * t))
