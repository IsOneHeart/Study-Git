def asterisk(num):
    if num != 0:
        asterisk(num - 1)
        for a in range(num):
            print("*", end="")
        print("")


n = int(input("n="))
asterisk(n)
