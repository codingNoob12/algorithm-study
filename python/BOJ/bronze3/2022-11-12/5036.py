n = int(input())
for _ in range(n):
    r, e, c = map(int, input().split())
    profit = e - c
    if r > profit:
        print('do not advertise')
    elif r < profit:
        print('advertise')
    else:
        print('does not matter')
