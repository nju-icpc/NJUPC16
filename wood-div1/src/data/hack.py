#!/usr/bin/env python2
import sys
n = int(sys.argv[1])
k = int(sys.argv[2])
print n, k
for i in range(k - 1) :
    print 1, i + 1
for i in range(k - 1, n) :
    print 1, 50000
