#!/usr/bin/env python2
import sys
n = int(sys.argv[1])

print n * n
for i in range(n) :
    for j in range(n) :
        print i * 1000, j * 1000
