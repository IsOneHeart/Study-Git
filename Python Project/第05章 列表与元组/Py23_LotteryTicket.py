import random

lotty = []
for num in range(7):
    lotty.append(random.randint(0, 9))
for num in range(len(lotty)):
    print(lotty[num])
