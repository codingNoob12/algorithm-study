t = int(input())
for _ in range(t):
    st = set(input())
    absentSum = (65 + 90) * 26 // 2
    for ch in st:
        absentSum -= ord(ch)
    print(absentSum)
