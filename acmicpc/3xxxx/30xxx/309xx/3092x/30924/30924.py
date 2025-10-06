al = list(range(1, 10001))
bl = list(range(1, 10001))

import random
random.shuffle(al)
random.shuffle(bl)

a = 0
while True:
    ad = al.pop()
    print("? A", ad, flush=True)
    dt = int(input())
    if dt == 1:
        a = ad
        break

b = 0
while True:
    bd = bl.pop()
    print("? B", bd, flush=True)
    dt = int(input())
    if dt == 1:
        b = bd
        break

print("!", a + b, flush=True)