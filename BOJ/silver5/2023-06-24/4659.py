import sys

def is_vowel(ch):
    return ch in ('a', 'e', 'i', 'o', 'u')

def is_valid(pw):
    if sum(map(is_vowel, pw)) == 0:
        return False
    for i in range(len(pw)):
        if i < len(pw) - 2 and (all(map(is_vowel, pw[i:i+3])) or sum(map(is_vowel, pw[i:i+3])) == 0):
            return False
        if i < len(pw) - 1 and (pw[i] == pw[i+1] and pw[i] not in ('e', 'o')):
            return False
    return True

for pw in sys.stdin.readlines()[:-1]:
    pw = pw.rstrip()
    if is_valid(pw):
        print(f'<{pw}> is acceptable.')
    else:
        print(f'<{pw}> is not acceptable.')
