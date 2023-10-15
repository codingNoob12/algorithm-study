for i in range(1, int(input()) + 1):
    print(f"Class {i}")
    n, *scores = map(int, input().split())
    scores.sort(reverse=True)
    diffList = [scores[i] - scores[i + 1] for i in range(n - 1)]
    print(f"Max {max(scores)}, Min {min(scores)}, Largest gap {max(diffList)}")
