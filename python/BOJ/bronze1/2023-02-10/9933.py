candidates = [input() for _ in range(int(input()))]
for i, candidate in enumerate(candidates):
    for comparison in candidates[:i] + candidates[i+1:]:
        if candidate[::-1] == comparison:
            length = len(candidate)
            print(length, candidate[length // 2])
            exit(0)
else:
    candidate = candidates[0]
    length = len(candidate)
    print(length, candidate[length // 2])
