from random import randint, choice
op = []
tt = randint(2, 1000000)
print(tt)
n = 0
bn = max(tt / 100, 10)
for _ in range(tt):
    c = '+'
    if len(op):
        c = choice('+-?!')
    elif n > 0:
        c = choice('+-?')
    else:
        c = choice('+?')
    k = 0
    if n <= bn and c == '-':
        c = '+'
    if c == '+':
        k = randint(1, 1000000)
        n += 1
        op.append(-1)
    elif c == '-':
        k = randint(1, n)
        n -= k
        op.append(k)
    elif c == '!':
        n += op.pop()
    if k > 0:
        print(c, k)
    else:
        print(c)
