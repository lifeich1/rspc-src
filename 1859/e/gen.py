from random import randint
tt = 5
print(tt)
for _ in range(tt):
    n = randint(5, 10)
    m = randint(1, n)
    print(n, m)
    for _ in range(n):
        print(randint(-99, 99), end=' ')
    print()
    for _ in range(n):
        print(randint(-99, 99), end=' ')
    print()
