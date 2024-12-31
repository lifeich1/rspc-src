from random import *

tt=3
print(tt)
for _ in range(tt):
    n,m=randint(1,100),randint(1,100)
    #n,m=100,100
    print(n,m)
    ans=randint(1,499999)
    r = 1000000//ans
    for _ in range(n):
        for _ in range(m):
            print(randint(1,r)*ans,end=' ')
        print()

