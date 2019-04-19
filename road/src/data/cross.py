#!/usr/bin/env python2
import sys
n = int(sys.argv[1])

print 4 * n
for i in range(1, n + 1) :
    print i, i
    print -i, i
    print -i, -i
    print i, -i
