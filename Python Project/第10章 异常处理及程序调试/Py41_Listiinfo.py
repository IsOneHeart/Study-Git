def func(listinfo):
    return_list = []
    for i in listinfo:
        if i < 100 and i % 2 == 0:
            return_list.append(i)
    return return_list


listinfo = [133, 88, 24, 33, 232, 44, 11, 44]
print(func(listinfo))
