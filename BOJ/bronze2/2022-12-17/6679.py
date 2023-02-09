def solve(x):
    dec = 0 # 10
    duoDec = 0 # 12
    hexaDec = 0 # 16
    for digit in str(x):
        dec += int(digit)
    for digit in hex(x)[2:]:
        hexaDec += int(digit, 16)
    while x:
        duoDec += x % 12
        x //= 12
    if dec == duoDec == hexaDec:
        return True
    return False

for i in range(1000, 10000):
    if solve(i):
        print(i)
