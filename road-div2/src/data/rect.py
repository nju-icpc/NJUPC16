#!/usr/bin/env python2
import sys
n = int(sys.argv[1])

print 4 * n
for i in range(n) :
    print i * 10000, 0
    print 0, (i + 1) * 10000
    print (i + 1) * 10000, n * 10000
    print n * 10000, i * 10000
