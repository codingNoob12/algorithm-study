def makePattern(n):
    if n == 3:
        top = bottom = "*" * 3
        mid = "*" + " " + "*"
        return [top, mid, bottom]

    offset = n // 3
    previous = makePattern(offset)
    blank = [" " * (offset) for _ in range(offset)]

    pattern = []
    # top
    for i in range(3):
        if i == 0:
            for row in previous:
                pattern.append(row)
        else:
            for i in range(len(previous)):
                pattern[i] += previous[i]

    # mid
    for i in range(3):
        if i == 0:
            for row in previous:
                pattern.append(row)
        elif i == 1:
            for i in range(len(blank)):
                pattern[i + offset] += blank[i]
        else:
            for i in range(len(previous)):
                pattern[i + offset] += previous[i]

    # bottom
    for i in range(3):
        if i == 0:
            for row in previous:
                pattern.append(row)
        else:
            for i in range(len(previous)):
                pattern[i + 2 * offset] += previous[i]

    return pattern


n = int(input())
for line in makePattern(n):
    print(line)
