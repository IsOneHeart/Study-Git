nums = input("请输入至少5个整数：")
num_spilt = nums.split()
for num in num_spilt:
    if ("A" <= num <= "Z" or "a" <= num <= "z") or float(num) % 1 != 0:
        print("TypeError：请输入整数！")
        exit(0)
if len(num_spilt) < 5:
    print("IndexError：请至少输入5个整数！")
    exit(0)
print(num_spilt)
