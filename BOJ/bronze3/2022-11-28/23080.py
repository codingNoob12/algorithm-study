k = int(input())
cipher = input()
decode = [cipher[i] for i in range(len(cipher)) if i % k == 0]
print(''.join(decode))
