bessiePos = list(map(int, input().split()))
daisyPos = list(map(int, input().split()))
johnPos = list(map(int, input().split()))
bessieXMove, bessieYMove = abs(bessiePos[0] - johnPos[0]), abs(bessiePos[1] - johnPos[1])
bessieMoveTime = max(bessieXMove, bessieYMove)
daisyXMove, daisyYMove = abs(daisyPos[0] - johnPos[0]), abs(daisyPos[1] - johnPos[1])
daisyMoveTime = daisyXMove + daisyYMove
if bessieMoveTime < daisyMoveTime:
    print('bessie')
elif bessieMoveTime > daisyMoveTime:
    print('daisy')
else:
    print('tie')
