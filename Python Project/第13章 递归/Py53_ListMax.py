def list_max(l):
    # 如果列表为空，返回None
    if not l:
        return None
    # 只有一个元素
    if len(l) == 1:
        return l[0]
    max_rest = list_max(l[1:])
    return l[0] if l[0] > max_rest else max_rest


testlist = [4, 6, 2, 7, 1, 7]
print("max:" + str(list_max(testlist)))
