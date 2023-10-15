t = int(input())
for _ in range(t):
    r, s = input().split()
    for ch in s:
        for _ in range(int(r)):
            print(ch, end='')
    print()
