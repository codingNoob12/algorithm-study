defen, defign = map(int, input().split())
if defen - defen * (defign / 100) >= 100:
    print(0)
else:
    print(1)
