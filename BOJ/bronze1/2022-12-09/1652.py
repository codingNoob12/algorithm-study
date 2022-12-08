def count(st: str):
    st += 'X'
    i, pre, cnt = -1, 0, 0
    while True:
        i = st.find('X', i + 1)
        if i == -1:
            if '..' in st[pre:]:
                cnt += 1
            break
        if '..' in st[pre:i]:
            cnt += 1
        pre = i + 1
    return cnt

room = [input() for _ in range(int(input()))]
r, c = 0, 0
for i in range(len(room)):
    r += count(room[i])
for j in range(len(room)):
    c += count(''.join([room[i][j] for i in range(len(room))]))
print(r, c)
