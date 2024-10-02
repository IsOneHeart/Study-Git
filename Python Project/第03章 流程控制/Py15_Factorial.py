num = int(input("请输入非负整数："))
if num < 0:
    print("输入的数必须是非负整数！")
else:
    if num == 0:
        print("0!=0")
    else:
        fac = num
        for i in list(range(1, num)):
            fac *= i
        print(num, "!=", fac, sep="")
