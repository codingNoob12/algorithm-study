def recursion(s, l, r):
    global cnt
    cnt += 1
    if l >= r:
        return 1
    if s[l] != s[r]:
        return 0
    return recursion(s, l+1, r-1)

def isPalindrome(s):
    return recursion(s, 0, len(s)-1)


for _ in range(int(input())):
    cnt = 0
    print(isPalindrome(input()), cnt)
