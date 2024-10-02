def pig_latin(string):
    new_string = ""
    words = string.split()  # 将输入的字符串分割成单词列表
    for word in words:
        new_string += (word[1:] + word[0] + "AY ")  # 将每个单词转换为 Pig Latin 格式并加入到新字符串中
    return (new_string.rstrip()).upper()  # 移除字符串末尾的空格并转换成大写


English = input("English（不含标点）:")
print("Pig Latin: " + pig_latin(English))
