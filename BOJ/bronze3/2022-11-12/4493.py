rspDict = {'R': 1, 'S': 2, 'P': 3}
def rsp2int(rsp):
    return rspDict[rsp]

t = int(input())
for _ in range(t):
    n = int(input())
    cnt1, cnt2 = 0, 0
    for _ in range(n):
        players = list(map(rsp2int, input().split()))
        if players[0] - players[1] in (-1, 2):
            cnt1 += 1
        elif players[0] - players[1] in (1, -2):
            cnt2 += 1
    if cnt1 < cnt2:
        print('Player 2')
    elif cnt1 > cnt2:
        print('Player 1')
    else:
        print('TIE')
