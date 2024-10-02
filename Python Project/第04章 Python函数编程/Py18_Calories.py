calories_from_fat = lambda fat: fat * 9
calories_from_carbs = lambda carbs: carbs * 4
fat_grams = float(input("请输入一天内摄入的脂肪的质量（克）："))
carbs_grams = float(input("请输入一天内摄入的碳水化合物的质量（克）："))
print("脂肪产生的卡路里："+str(calories_from_fat(fat_grams)))
print("碳水化合物产生的卡路里："+str(calories_from_carbs(carbs_grams)))