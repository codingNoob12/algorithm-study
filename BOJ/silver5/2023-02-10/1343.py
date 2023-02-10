tiles = ['AAAA', 'BB']
answer = ''
st = input()
coverList = st.split('.')
for cover in coverList:
    if not cover:
        answer += '.'
    elif len(cover) % 2 == 0:
        for _ in range(len(cover) // 4):
            answer += tiles[0]
        for _ in range(len(cover) % 4 // 2):
            answer += tiles[1]
        st = st.replace(cover, '', 1)
        answer += '.'
    else:
        print(-1)
        exit(0)
print(answer[:-1])
