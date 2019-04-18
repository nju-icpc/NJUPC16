#!/usr/bin/python2

import random

random.seed(2923243)
lf = [0, 6, 7]
for _ in range(1000) :
    lf.append(lf[-1] + lf[-2])

q = []

for i in range(100, 501) :
    q.append((i, 1000000000000))

print len(q)
random.shuffle(q)
for i, j in q :
    print i, j

