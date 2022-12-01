for _ in range(int(input())):
    pos, st = input().split()
    tmp = list(st)
    tmp.pop(int(pos)-1)
    print(*tmp, sep='')
