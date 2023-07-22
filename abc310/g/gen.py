from random import randint
n = randint(2, 16)
k = randint(1, 22)
print(n, k)
a = [randint(1, n) for _ in range(n)]
b = [randint(0, 9) for _ in range(n)]
for x in a:
    print(x, end=' ')
print()
for x in b:
    print(x, end=' ')
print()

s = [0] * n
print('========')
for _ in range(k):
    t = [0] * n
    for i in range(n):
        t[a[i]-1] += b[i]
    b = t
    for x in b:
        print(x, end=' ')
    print()
    for i in range(n):
        s[i] += b[i]

print('sum:')
for x in s:
    print(x, end=' ')
print()
