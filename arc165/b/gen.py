from random import randint, shuffle
n = randint(1, 33)
k = randint(1, n)
l = list(range(1, n+1))
shuffle(l)
print(n, k)
for x in l:
    print(x, end=' ')
print()
