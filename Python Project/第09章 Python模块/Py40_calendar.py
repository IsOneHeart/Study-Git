import calendar

help(calendar.isleap)

def nextleap(year):
    year+=1
    while calendar.isleap(year)==False:
        year+=1
    return year

year=int(input("请输入年份："))
print("下一个闰年是",nextleap(year),"年",sep="")
print("\n",dir(calendar))
print("2000年至2025年（包含）间的闰年个数："+str(calendar.leapdays(1999,2026)))
print("2016年7月29日是周"+str(calendar.weekday(2016,7,29)))