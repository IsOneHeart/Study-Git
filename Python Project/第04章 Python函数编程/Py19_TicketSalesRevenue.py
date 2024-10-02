def tsr(a, b, c):
    return 20 * a + 15 * b + 10 * c


a = int(input("A类作为卖出数量："))
b = int(input("B类作为卖出数量："))
c = int(input("C类作为卖出数量："))
print("销售收入：", tsr(a, b, c), sep="")
