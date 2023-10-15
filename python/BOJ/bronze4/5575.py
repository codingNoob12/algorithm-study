for _ in range(3):
    timeList = list(map(int, input().split()))
    start = timeList[0] * 3600 + timeList[1] * 60 + timeList[2]
    end = timeList[3] * 3600 + timeList[4] * 60 + timeList[5]
    work = end - start
    s = work % 60
    m = work // 60 % 60
    h = work // 3600 % 24
    print(h, m, s)
