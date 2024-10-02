# 定义一个自定义异常类
class IllegalArgumentException(Exception):
    def __init__(self, message):
        self.message = message
        super().__init__(self.message)


def sanjiao(a,b,c):
    if a+b>c and a+c>b and b+c>a:
        print("三角形边长{0}、{1}、{2}".format(a,b,c))
    else:
        # 触发自定义异常
        raise IllegalArgumentException("无法构成三角形！")


a=float(input("输入边a长："))
b=float(input("输入边b长："))
c=float(input("输入边c长："))
sanjiao(a,b,c)