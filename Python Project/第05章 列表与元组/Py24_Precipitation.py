precipitation = []
for month in range(12):
    preM = float(input(("请输入{0}月的降水量：".format(month+1))))
    precipitation.append(preM)
print("总降水量：", sum(precipitation))
print("月平均降水量：", sum(precipitation) / 12)
print("最高降水量：", max(precipitation))
print("最低降水量：", min(precipitation))
