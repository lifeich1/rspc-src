from random import randint
n = randint(3, 20)
print(''.join([chr(ord('a') + randint(0, 2)) for _ in range(n)]))
q = 4
print(q)
for _ in range(q):
    s, t = randint(1, n-1), randint(2, n-1)
    if s == t:
        t -= 1
    print(s, t)
