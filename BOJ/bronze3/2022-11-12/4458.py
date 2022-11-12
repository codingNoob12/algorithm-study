t = int(input())
for _ in range(t):
    sentence = input()
    if sentence[0].islower():
        sentence = sentence[0].upper() + sentence[1:]
    print(sentence)
