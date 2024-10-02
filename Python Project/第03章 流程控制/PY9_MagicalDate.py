year=int(input("请输入年份：（用两位数字表示）"))
month=int(input("请输入月份："))
day=int(input("请输入日期："))
if year==month*day:
    print("这是神奇的一天！")
else:
    print("这是普通的一天。")