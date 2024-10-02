def vowel(string):
    vowel_count = 0
    for v in string.lower():
        if "aeiou".find(v) != -1:
            vowel_count += 1
    return vowel_count


def consonant(string):
    consonant_count = 0
    for v in string.lower():
        if "aeiou".find(v) == -1:
            consonant_count += 1
    return consonant_count


string_input = str(input("请输入字符串："))
print("元音数量：", vowel(string_input))
print("辅音数量：", consonant(string_input))
