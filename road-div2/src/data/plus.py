#!/usr/bin/env python2
import sys
n = int(sys.argv[1])

print 4 * n
for i in range(1, n + 1) :
    print i, 0
    print 0, i
    print -i, 0
    print 0, -i
