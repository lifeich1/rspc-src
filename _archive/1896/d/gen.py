from random import randint

tt = 2
print(tt)
for _ in range(tt):
    n, q = randint(1, 10), randint(1, 10)
    print(n, q)
    print(' '.join([str(randint(1, 2)) for _ in range(n)]))
    for _ in range(q):
        op = randint(1, 2)
        s = randint(1, n+n)
        i, v = randint(1, n), randint(1, 2)
        if 1 == op:
            print(op, s)
        else:
            print(op, i, v)
