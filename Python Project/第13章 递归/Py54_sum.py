def sum_r(l):
    # 如果列表为空，返回None
    if not l:
        return None
    # 只有一个元素
    if len(l) == 1:
        return l[0]
    next_sum = sum_r(l[1:])
    return l[0] + next_sum


testlist = [4, 6, 2, 7, 1, 7]
print("sum=" + str(sum_r(testlist)))
