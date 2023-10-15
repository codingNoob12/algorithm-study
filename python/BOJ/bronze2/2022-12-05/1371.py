import sys
cnt = [0] * 26
for line in sys.stdin.readlines():
    for ch in line.strip():
        if ch == ' ':
            continue
        cnt[ord(ch)-97] += 1
maxCnt = max(cnt)
for i in range(26):
    if cnt[i] == maxCnt:
        print(chr(i + 97), end='')
