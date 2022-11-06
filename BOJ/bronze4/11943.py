a, b = map(int, input().split())
c, d = map(int, input().split())
appOrn = b + c
ornApp = a + d
print(min(appOrn, ornApp))
