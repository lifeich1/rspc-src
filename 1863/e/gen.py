from random import randint
print(1)
n = randint(2, 9)
m = randint(0, 10)
k = randint(1, 24)
print(n, m, k)
for _ in range(n):
    print(randint(0, k-1), end=' ')
print()
for _ in range(m):
    l, r = randint(1, n), randint(2, n)
    if l >= r:
        r -= 1
        l, r = r, l
    print(l, r)
