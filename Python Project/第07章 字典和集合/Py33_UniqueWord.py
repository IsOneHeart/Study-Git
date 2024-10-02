def unique(string):
    words = string.split()  # 将输入的字符串分割成单词列表
    words_dic = {}
    for word in words:
        if words_dic.get(word, "default") == "default":
            words_dic[word] = 1
        else:
            words_dic[word] += 1
    print(words_dic)
    words_set = set()
    for word in words_dic:
        if words_dic[word] == 1:
            words_set.add(word)
    print(words_set)


string_input = str(input("请输入单词串："))
unique(string_input)
