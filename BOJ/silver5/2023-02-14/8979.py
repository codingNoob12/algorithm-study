n, k = map(int, input().split())
NATIONS = {}
for _ in range(n):
    i, *medals = map(int, input().split())
    NATIONS[i] = medals
rank = 1
for nation, medals in NATIONS.items():
    if nation == k:
        continue
    if NATIONS[k][0] < medals[0] or \
            NATIONS[k][0] == medals[0] and NATIONS[k][1] < medals[1] or \
            NATIONS[k][0] == medals[0] and NATIONS[k][1] == medals[1] and NATIONS[k][2] < medals[2]:
        rank += 1
print(rank)
