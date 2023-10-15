for _ in range(int(input())):
    st1, st2 = input().split()
    distances = []
    for i in range(len(st1)):
        tmp = ord(st2[i]) - ord(st1[i])
        if tmp < 0:
            tmp += 26
        distances.append(tmp)
    print('Distances:', *distances)
