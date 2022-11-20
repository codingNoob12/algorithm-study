aAtt, aLife = map(int, input().split())
bAtt, bLife = map(int, input().split())
aLive = (aLife - 1) // bAtt + 1
bLive = (bLife - 1) // aAtt + 1
if aLive > bLive:
    print('PLAYER A')
elif aLive < bLive:
    print('PLAYER B')
else:
    print('DRAW')
