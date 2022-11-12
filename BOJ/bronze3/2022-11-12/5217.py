tc = int(input())
for _ in range(tc):
    n = int(input())
    print(f'Pairs for {n}: ', end='')
    if 1 < n - 1:
        print(1, n-1, end='')
    for i in range(2, (n-1)//2+1):
        print(',', i, n - i, end='')
    print()
