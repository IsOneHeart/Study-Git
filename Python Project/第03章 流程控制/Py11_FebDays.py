year = int(input("请输入年份："))
isR = 0
if year % 100 == 0:
    if year % 400 == 0:
        isR = 1
else:
    if year % 4 == 0:
        isR = 1
if isR == 1:
    print("该年二月有29天")
else:
    print("该年二月有28天")
