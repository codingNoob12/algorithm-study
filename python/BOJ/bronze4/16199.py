bornDate = list(map(int, input().split()))
nowDate = list(map(int, input().split()))
americanAge = nowDate[0] - bornDate[0]
if nowDate[1] < bornDate[1] or (nowDate[1] == bornDate[1] and nowDate[2] < bornDate[2]):
    americanAge -= 1
koreanAge = nowDate[0] - bornDate[0] + 1
yearAge = nowDate[0] - bornDate[0]
print(americanAge, koreanAge, yearAge, sep='\n')
