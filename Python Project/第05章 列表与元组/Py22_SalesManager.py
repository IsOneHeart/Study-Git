sumWeek = 0
salesWeek = []
for i in range(1, 8):
    sales = float(input(("第{0}天销售额：".format(i))))
    salesWeek.append(sales)
    sumWeek += sales
print("本周销售总额：" + str(sumWeek))
