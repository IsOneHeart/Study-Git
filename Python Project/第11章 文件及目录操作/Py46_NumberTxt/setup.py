import random

if __name__ == "__main__":
    with open("number.txt", "w", encoding="utf-8") as file:
        for i in range(10):
            file.write(str(random.randint(1, 501)) + " ")
        file.flush()
        print("文件写入成功！")
        file.close()
