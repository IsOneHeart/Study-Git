def main():
    n = int(input("n="))
    print_num(n)


def print_num(n):
    if n == 0:
        return
    else:
        print_num(n - 1)
        print(n, end=" ")


if __name__ == "__main__":
    main()
