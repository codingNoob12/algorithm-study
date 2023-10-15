cups = [True, False, False]

def swap(ch):
    if ch == 'A':
        cups[0], cups[1] = cups[1], cups[0]
    elif ch == 'B':
        cups[1], cups[2] = cups[2], cups[1]
    else:
        cups[0], cups[2] = cups[2], cups[0]

for ch in input():
    swap(ch)
print(cups.index(True) + 1)
