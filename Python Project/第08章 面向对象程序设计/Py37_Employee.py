class Employee:
    def __init__(self):
        self.id_dic = {}

    def add_dic(self):
        add_id = input("要添加的ID：")
        if add_id not in self.id_dic:
            new_name = input("姓名：")
            new_department = input("部门：")
            new_position = input("职位：")
            self.id_dic[add_id] = {"name": new_name, "department": new_department, "position": new_position}
            return self.id_dic
        print("ID已存在！")

    def del_dic(self):
        del_id = input("请输入要删除的雇员ID")
        if del_id in self.id_dic:
            del self.id_dic[del_id]
        else:
            print("ID不存在!")

    def sec_dic(self):
        sec_id = input("请输入要查找的雇员ID：")
        if sec_id in self.id_dic:
            print(self.id_dic[sec_id])
        else:
            print("ID不存在!")

    def cha_dic(self):
        cha_id = input("要修改的ID：")
        if cha_id in self.id_dic:
            new_name = input("姓名：")
            new_department = input("部门：")
            new_position = input("职位：")
            self.id_dic[cha_id] = {"name": new_name, "department": new_department, "position": new_position}
            return self.id_dic
        print("ID不存在!")

    def list(self):
        while True:
            print("==========菜单=========")
            print("查找雇员【0】 添加新员工【1】")
            print("更改信息【2】 删除员工【3】")
            print("退出程序【4】")
            print("======================")
            menu = int(input("输入选项："))
            if menu == 0:
                self.sec_dic()
            elif menu == 1:
                self.add_dic()
            elif menu == 2:
                self.cha_dic()
            elif menu == 3:
                self.del_dic()
            else:
                exit(0)


employee = Employee()
employee.list()
