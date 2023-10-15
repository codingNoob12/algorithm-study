t = int(input())
for _ in range(t):
    hp, mp, att, defn, varHp, varMp, varAtt, varDefn = map(int, input().split())
    hp += varHp
    mp += varMp
    att += varAtt
    defn += varDefn
    if hp < 1:
        hp = 1
    if mp < 1:
        mp = 1
    if att < 0:
        att = 0
    power = hp + 5 * mp + 2 * att + 2 * defn
    print(power)
