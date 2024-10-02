"""
编写一个程序，读取两个字符串的内容，并进行以下操作：
显示包含在这两个字符串中的唯一单词列表。
显示出现在两个字符串中的单词列表。
显示出现在第一个字符串但在第二个字符串中没有出现的单词列表。
显示出现在第二个字符串但在第一个字符串中没有出现的单词列表。
提示：使用集合操作进行比较
"""
str1 = str(input("请输入第一个字符串："))
str2 = str(input("请输入第二个字符串："))


def unique(string):
    words = string.split()  # 将输入的字符串分割成单词列表
    words_dic = {}
    for word in words:
        if words_dic.get(word, "default") == "default":
            words_dic[word] = 1
        else:
            words_dic[word] += 1
    words_list = []
    for word in words_dic:
        if words_dic[word] == 1:
            words_list.append(word)
    return words_list


def sep_word(string):
    words = string.split()
    words_list = []
    for word in words:
        if word in words_list:
            continue
        else:
            words_list.append(word)
    return words_list


def com_word(string1, string2):
    words1, words2 = string1.split(), string2.split()
    word_set1 = set()
    word_set2 = set()
    for word in words1:
        word_set1.add(word)
    for word in words2:
        word_set2.add(word)
    return list(word_set1 - word_set2)


unique_word_list = unique(str1 + " " + str2)
print("包含在这两个字符串中的唯一单词列表：", unique_word_list, sep="")
sep_word_list = sep_word(str1 + " " + str2)
print("出现在两个字符串中的单词列表：", sep_word_list, sep="")
print("出现在第一个字符串但在第二个字符串中没有出现的单词列表：", com_word(str1, str2), sep="")
print("出现在第二个字符串但在第一个字符串中没有出现的单词列表：", com_word(str2, str1), sep="")
