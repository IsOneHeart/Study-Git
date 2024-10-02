import random

list_random = []
for i in range(3):
    list_random.append(random.randint(1, 101))
print(list_random)
try:
    print(list_random[len(list_random) + 1])
except IndexError as e:
    print("IndexError!")
finally:
    print("END")
