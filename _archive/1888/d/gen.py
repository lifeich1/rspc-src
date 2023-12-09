from random import randint

tt = randint(1, 3)
print(tt)
for _ in range(tt):
    n, m = randint(2, 10), randint(1, 9)
    print(n, m)
    for _ in range(n-1):
        print(randint(1, 99), end=' ')
    print()
    for _ in range(n):
        print(randint(1, 99), end=' ')
    print()
