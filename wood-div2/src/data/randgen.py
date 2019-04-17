#!/usr/bin/env python2
import random, math
import sys
n = int(sys.argv[1])
k = int(sys.argv[2])
xbnd = int(sys.argv[3])
ybnd = int(sys.argv[4])
random.seed(int(sys.argv[5]))
print n, k
for i in range(n) :
    print random.randint(1, xbnd), random.randint(1, ybnd)
