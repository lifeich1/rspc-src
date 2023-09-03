from random import randint
n = randint(1, 8)
print(n)
M = 10**18
ls = [randint(-M, M-n) for _ in range(n)]
ls.sort()
for i in range(1, n):
    if ls[i] <= ls[i-1]:
        ls[i] = ls[i-1] + 1
for x in ls:
    print(x, end=' ')
print()
ls = sorted([randint(1, M) for _ in range(n)])
for x in ls:
    print(x, end=' ')
print()
