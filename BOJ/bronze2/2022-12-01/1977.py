m = int(input())
n = int(input())
squares = [i ** 2 for i in range(1, 101)]
target = list(filter(lambda x: m <= x <= n, squares))
if len(target) == 0:
    print(-1)
else:
    print(sum(target), min(target), sep='\n')
