t = int(input())
for _ in range(t):
    h, w, n = map(int, input().split())
    c = (n - 1) // h + 1
    r = (n - 1) % h + 1
    print(f'{r}{c:02d}')
