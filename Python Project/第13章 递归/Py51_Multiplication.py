def multiplication(xNum, yNum):
    if xNum == 0 or yNum == 0:
        return 0
    return xNum + multiplication(xNum, yNum - 1)


x = int(input("x="))
y = int(input("y="))
print(multiplication(x, y))
