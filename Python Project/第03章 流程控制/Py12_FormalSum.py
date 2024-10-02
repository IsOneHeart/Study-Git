sumF = 0
while True:
    formal = float(input("输入正数以累加，输入负数以结束："))
    if formal >= 0:
        sumF += formal
    else:
        break
print("sum=" + str(sumF))
