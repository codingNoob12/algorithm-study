import math

a, b = map(int, input().split())
horizontal = math.ceil(b / 4) - math.ceil(a / 4)
vertical = abs(b - (a + horizontal * 4))
print(abs(horizontal) + vertical)
