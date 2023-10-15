maxPassenger, passenger = 0, 0
for _ in range(10):
    getOff, getIn = map(int, input().split())
    passenger += getIn - getOff
    if maxPassenger < passenger:
        maxPassenger = passenger
print(maxPassenger)
