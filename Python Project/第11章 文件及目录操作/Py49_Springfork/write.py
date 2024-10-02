sf_dic={}
print("输入信息：(姓名#标记结束）")
with open("Springfork.txt","w",encoding="utf-8") as file:
    name=input("姓名：")
    if name=="#":
        exit(0)
    mark = float(input("成绩："))
    while True:
        sf_dic[name]=mark
        name = input("姓名：")
        if name == "#":
            break
        mark = float(input("成绩："))
    file.write(str(sf_dic))