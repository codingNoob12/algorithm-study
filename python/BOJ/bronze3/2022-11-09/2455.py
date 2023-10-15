maxPassenger, passenger = 0, 0
for i in range(4):
    getOff, getIn = map(int, input().split())
    passenger += getIn - getOff
    if maxPassenger < passenger:
        maxPassenger = passenger
print(maxPassenger)
