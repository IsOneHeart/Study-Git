# 从Springfork.txt文件中读取记录并显示
with open("Springfork.txt", "r", encoding="utf-8") as file:
    data = file.read()
    # 将读取的数据转换为字典
    sf_dic = eval(data)
    print("从文件中读取的记录：")
    for name, mark in sf_dic.items():
        print(f"姓名: {name}, 成绩: {mark}")
