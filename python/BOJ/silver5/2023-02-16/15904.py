abbr = "UCPC"
for ch in input():
    if ch == abbr[0]:
        abbr = abbr[1:]
    if not abbr:
        print("I love UCPC")
        break
else:
    print("I hate UCPC")
