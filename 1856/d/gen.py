from random import *
tt = 5
print(tt)
for _ in range(tt):
    n = randint(1200, 2000)
    print(n)
    a = list(range(1,n+1))
    shuffle(a)
    print(' '.join(map(str,a)))
