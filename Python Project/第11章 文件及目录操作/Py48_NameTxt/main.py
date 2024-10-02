with open("name.txt", "r", encoding="utf-8") as file:
    word = file.readline()
    num = 0
    while word != "":
        num += 1
        word = file.readline()
    print("姓名个数："+str(num))
