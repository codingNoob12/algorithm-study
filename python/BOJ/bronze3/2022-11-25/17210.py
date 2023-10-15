n = int(input())
openWay = int(input())
ways = []
for i in range(2, n+1):
    openWay = (openWay + 1) % 2
    if len(ways) > 0 and i % 2 == 0 and ways[0] != openWay:
        print('Love is open door')
        exit(0)
    if len(ways) > 1 and i % 3 == 0 and ways[1] != openWay:
        print('Love is open door')
        exit(0)
    ways.append(openWay)
print(*ways, sep='\n')
