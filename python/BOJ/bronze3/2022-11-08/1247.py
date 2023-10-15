import sys
for _ in range(3):
    n = int(sys.stdin.readline().strip())
    sumVal = 0
    for _ in range(n):
        sumVal += int(sys.stdin.readline().strip())
    if sumVal > 0:
        sys.stdout.write("+\n")
    elif sumVal == 0:
        sys.stdout.write("0\n")
    else:
        sys.stdout.write("-\n")
