#!/usr/bin/python2

lf = [6, 7]
for _ in range(100) :
    lf.append(lf[-1] + lf[-2])

print list(enumerate(lf))
