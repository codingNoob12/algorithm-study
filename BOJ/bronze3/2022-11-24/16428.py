a, b = map(int, input().split())
quo, rem = a // b, a % b
if rem < 0:
    rem -= b
    quo += 1
print(quo, rem, sep='\n')
