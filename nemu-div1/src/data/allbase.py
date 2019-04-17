#!/usr/bin/python2
import sys, random
b = int(sys.argv[1])
random.seed(int(sys.argv[2]))

ld = range(1, b)
x = [random.choice(ld) for _ in range(64)]
c = 1
ans = 0
for xv in x :
    ans += xv * c
    c *= b
print ans % (2 ** 64)
