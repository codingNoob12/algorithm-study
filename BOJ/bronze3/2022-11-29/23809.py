def section1(n):
    for i in range(n):
        print('@' * n + ' ' * (3 * n) + '@' * n)

def section2(n):
    for i in range(n):
        print('@' * n + ' ' * (2 * n) + '@' * n)

def section3(n):
    for i in range(n):
        print('@' * (3 * n))

n = int(input())
section1(n)
section2(n)
section3(n)
section2(n)
section1(n)
