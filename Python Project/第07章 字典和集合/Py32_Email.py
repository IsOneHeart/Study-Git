"""
编写一个程序，将姓名和电子邮件地址以键值对形式保存。该程序显示菜单让用户查看一个人的邮件地址，或者添加一个新姓名及其邮件地址，
或者修改已经经存在的邮件地址，或者删除一个已经存在的姓名及其邮件地址，或者退出程序。根据用户的选择设置相应的操作。
"""

contacts = {}


def display_menu():
    print("1. 查看邮件地址")
    print("2. 添加新姓名及其邮件地址")
    print("3. 修改已存在的邮件地址")
    print("4. 删除已存在的姓名及其邮件地址")
    print("5. 退出程序")


def view_email():
    name = input("请输入要查看邮件地址的姓名：")
    if name in contacts:
        print(f"{name} 的邮箱地址是：{contacts[name]}")
    else:
        print("找不到该姓名的邮件地址")


def add_contact():
    name = input("请输入姓名：")
    email = input("请输入邮件地址：")
    contacts[name] = email
    print("联系人信息已添加成功")


def modify_email():
    name = input("请输入要修改邮件地址的姓名：")
    if name in contacts:
        new_email = input("请输入新的邮件地址：")
        contacts[name] = new_email
        print("邮件地址已更新")
    else:
        print("找不到该姓名的邮件地址")


def delete_contact():
    name = input("请输入要删除的姓名：")
    if name in contacts:
        del contacts[name]
        print("联系人信息已删除")
    else:
        print("找不到该姓名的邮件地址")


while True:
    display_menu()
    choice = input("请选择操作（输入数字）：")

    if choice == '1':
        view_email()
    elif choice == '2':
        add_contact()
    elif choice == '3':
        modify_email()
    elif choice == '4':
        delete_contact()
    elif choice == '5':
        print("程序已退出")
        break
    else:
        print("无效的选择，请重新输入")
