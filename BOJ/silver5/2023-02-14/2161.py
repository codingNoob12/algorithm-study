from collections import deque
cards = deque([i for i in range(1, int(input()) + 1)])
while True:
    print(cards.popleft(), end=' ')
    if not cards:
        break
    cards.append(cards.popleft())
