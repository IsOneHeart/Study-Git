def pig_latin(string):
    new_string = ""
    start = 0
    end = 0
    for i in range(len(string)):
        if string[i] == " " or i == len(string) - 1:
            if i == len(string) - 1:
                end = i
            else:
                end = i - 1
            new_string += (string[start+1:end+1] + string[start] + "AY ")
            start = i + 1
    return (new_string.rstrip()).upper()


English = input("English（不含标点）:")
print("Pig Latin: " + pig_latin(English))
