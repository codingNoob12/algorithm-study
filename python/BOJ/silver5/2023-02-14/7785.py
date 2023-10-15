NAMES = set()
for _ in range(int(input())):
    name, status = input().split()
    if status == 'enter':
        NAMES.add(name)
    else:
        NAMES.remove(name)
print(*sorted(NAMES, reverse=True), sep='\n')
