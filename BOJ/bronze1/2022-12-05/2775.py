def getNextFloorResidents(residents: list):
    currentFloor = []
    for i in range(1, 15):
        currentFloor.append(sum(residents[-1][:i]))
    residents.append(currentFloor)

residents = [[i for i in range(1, 15)]]
for i in range(1, 15):
    getNextFloorResidents(residents)
for _ in range(int(input())):
    k = int(input())
    n = int(input())
    print(residents[k][n-1])
