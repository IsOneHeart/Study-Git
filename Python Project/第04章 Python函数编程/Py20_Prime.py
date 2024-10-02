def is_prime(num):
    if num == 1:
        return False
    for i in list(range(2, num - 1)):
        if num % i == 0:
            return False
    return True


num = int(input("请输入一个正整数："))
print(is_prime(num))
