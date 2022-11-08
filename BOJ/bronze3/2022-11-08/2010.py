import sys
n = int(sys.stdin.readline().strip())
con = 0
for _ in range(n):
    con += int(sys.stdin.readline().strip())
    con -= 1
con += 1
print(con)
