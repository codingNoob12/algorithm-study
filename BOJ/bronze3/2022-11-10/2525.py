from datetime import timedelta
a, b = map(int, input().split())
c = int(input())
res = timedelta(hours=a, minutes=b) + timedelta(minutes=c)
print(res.seconds // 3600, res.seconds // 60 % 60)
