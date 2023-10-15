import sys
input = sys.stdin.readline
i = 1
while True:
    l, p, v = map(int, input().split())
    if l == p == v == 0:
        break
    use = (v // p) * l + (v % p if v % p < l else l)
    print(f'Case {i}: {use}')
    i += 1
