emoticons = [':-)', ':-(']
statement = input()
happyCount = statement.count(emoticons[0])
sadCount = statement.count(emoticons[1])
if happyCount == 0 and sadCount == 0:
    print('none')
elif happyCount < sadCount:
    print('sad')
elif happyCount > sadCount:
    print('happy')
else:
    print('unsure')
