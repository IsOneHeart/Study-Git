def ds(string):
    string_sum = 0
    for num in string:
        string_sum += int(num)
    return string_sum


string_input = input("请输入一串无分隔的数字字符串：")
print(ds(string_input))
