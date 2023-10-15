n, m = map(int, input().split())
dnaList = sorted(input() for _ in range(n))
count = 0

for j in range(m):
    COUNTS = {"A": 0, "C": 0, "G": 0, "T": 0}

    for i in range(n):
        COUNTS[dnaList[i][j]] += 1

    nucleotide = max(COUNTS, key=COUNTS.get)
    count += sum(COUNTS.values()) - COUNTS[nucleotide]
    print(nucleotide, end="")
print("", count, sep="\n")
