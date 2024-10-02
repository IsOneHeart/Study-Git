Ordering_Fee = float(input("请输入点餐费用："))
Tip = Ordering_Fee * 0.18
Consumption_Tax = Ordering_Fee * 0.07
Total_Consumption = Ordering_Fee+Tip+Consumption_Tax
print("小费："+str(format(Tip,".2f")))
print("消费税："+str(format(Consumption_Tax,".2f")))
print("消费总额："+str(format(Total_Consumption,".2f")))