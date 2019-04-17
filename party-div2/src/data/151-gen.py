#!/usr/bin/python2
n = 5000
print n
for _ in range(n) :
    if n & 1:
        print 0, 0
    else :
        print 1000000000, 1000000000
