fee = 8000
i = 1
while i <= 5:
    fee = fee * (1 + 0.03)
    print("未来", i, "年学费：", format(fee,".2f"), "元", sep="")
    i += 1
