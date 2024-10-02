def name(name_string):
    new_name = ""
    for char in name_string:
        if 'A' <= char <= 'Z':
            new_name += (char + ".")
    new_name = new_name.rstrip(".")
    return new_name


name_input = input(str("请输入英文姓名："))
print(name(name_input))
