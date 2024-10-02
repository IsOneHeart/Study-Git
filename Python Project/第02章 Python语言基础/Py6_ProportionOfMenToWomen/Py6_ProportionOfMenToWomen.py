numM = int(input("请输入班级男生人数："))
numF = int(input("请输入班级女生人数："))
Total = numM + numF
print("班级男生比例为", str(format(numM/Total,".2%")), "，班级女生比例为", str(format(numF/Total,".2%")), sep="")
