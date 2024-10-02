import random


def bigger(listnum, n):
    isB = 0
    for i in listnum:
        if i > n:
            print(i)
            isB = 1
    if isB == 0:
        print("None")


random_list = []
for num in range(10):
    random_list.append(random.randint(0, 9))
print("比5大的数：")
bigger(random_list, 5)
