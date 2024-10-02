quantity = int(input("请输入要批量购买的游戏数量："))
if quantity < 10:
    total = float(99 * quantity)
elif quantity < 20:
    total = float(99 * quantity * 0.9)
elif quantity < 50:
    total = float(99 * quantity * 0.8)
elif quantity < 100:
    total = float(99 * quantity * 0.7)
else:
    total = float(99 * quantity * 0.6)
discount = 99 * quantity - total
print("折扣：", discount, "美元", sep="")
print("折后总价：", total, "美元", sep="")
