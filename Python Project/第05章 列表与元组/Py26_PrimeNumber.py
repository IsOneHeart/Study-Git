def prime(n):
    if n < 2:
        return False
    else:
        num_list = range(2, n)
        for i in num_list:
            if n % i == 0:
                return False
    return True


num = int(input("输入一个数判断是否为素数："))
print(prime(num))
