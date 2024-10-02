if __name__ == "__main__":
    with open("number.txt", "r", encoding="utf-8") as file:
        try:
            nums_str = str(file.readline()).split()
            if not nums_str:
                print("文件为空，无法计算平均值")
            else:
                sum_num = 0
                i = 0
                for num in nums_str:
                    try:
                        sum_num += int(num)
                        i += 1
                    except ValueError:
                        print(f"无法将 '{num}' 转换为整数")

                if i == 0:
                    print("无有效数据，无法计算平均值")
                else:
                    print("和：" + str(sum_num))
                    print("平均值：" + str(sum_num / i))
        except ValueError:
            print("文件读取错误")