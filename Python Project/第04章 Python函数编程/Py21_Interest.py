def f(p0, i0, t0):
    return p0 * (1 + i0) ** t0


p = float(input("请输入账户的现值："))
i = float(input("请输入月利率："))
t = float(input("请输入钱存在账户中的月数："))
print("账户的未来价值：", f(p, i, t), sep="")
