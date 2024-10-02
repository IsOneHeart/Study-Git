age=int(input("请输入年龄："))
if age<=3:
    print("此人为婴儿")
elif age<13:
    print("此人为儿童")
elif age<18:
    print("此人为青少年")
else:
    print("此人为成年人")