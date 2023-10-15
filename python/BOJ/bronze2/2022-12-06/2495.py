for _ in range(3):
    sequenceList = [0] * 10
    againList = []
    previous = -1
    for digit in input():
        d = int(digit)
        if previous == d:
            sequenceList[d-1] += 1
        else:
            if previous != -1 and sequenceList[previous-1]:
                againList.append(sequenceList[previous-1])
            sequenceList[d-1] = 1
        previous = d
    print(max(max(sequenceList), max(againList) if againList else 0))
