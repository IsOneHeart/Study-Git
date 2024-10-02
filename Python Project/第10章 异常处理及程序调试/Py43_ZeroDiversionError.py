a = int(input("请输入被除数a："))
b = int(input("请输入除数b："))
if b == 0:
    raise ZeroDivisionError
else:
    print("a/b="+str(a/b))
