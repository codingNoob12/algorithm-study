a, b, c = map(int, input().split())
candidates = [a, b, c, a * b, a * c, b * c, a * b * c]
odds = [candidate for candidate in candidates if candidate % 2]
evens = [candidate for candidate in candidates if candidate % 2 == 0]
if len(odds) != 0:
    print(max(odds))
else:
    print(max(evens))
