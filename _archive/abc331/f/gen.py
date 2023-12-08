from random import randint

n = 7
q = 7
print(n, q)
s = ''.join([chr(ord('a') + randint(0, 25)) for _ in range(n)])
print(s)
for _ in range(q):
    t = randint(1, 2)
    if t == 1:
        print(1, randint(1, n), chr(ord('a') + randint(0, 25)))
    else:
        l, r = randint(1, n), randint(1, n)
        if l > r:
            l, r = r, l
        print(2, l, r)
