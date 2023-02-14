from math import gcd


def lcd(x, y):
    return x * y // gcd(x, y)


a, b = map(int, input().split())
print(lcd(a, b))
