import string

def isAnagram(a: str, b: str):
    for ch in string.ascii_lowercase:
        if a.count(ch) != b.count(ch):
            return False
    return True

for _ in range(int(input())):
    a, b = input().split()
    if isAnagram(a, b):
        print(f'{a} & {b} are anagrams.')
    else:
        print(f'{a} & {b} are NOT anagrams.')
