m = float(input("请输入物业的更换成本："))
minP = lambda num: m * 0.8
print("应购买财产险的最小金额：", minP(m), sep="")
