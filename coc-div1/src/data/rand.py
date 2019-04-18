#!/usr/bin/python2

import random, sys

random.seed(int(sys.argv[1]))
lf = [0, 6, 7]
for _ in range(1000) :
    lf.append(lf[-1] + lf[-2])

q = []

for i in range(1, 1000) :
    x = random.randint(1, 500)
    y = random.randint(1, min(1000000000000, lf[x]))
    q.append((x, y))

print len(q)
random.shuffle(q)
for i, j in q :
    print i, j 
