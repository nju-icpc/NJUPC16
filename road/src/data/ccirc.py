#!/usr/bin/env python2
import sys, math
from math import *
n = int(sys.argv[1])

print n
print 0, 0
n -= 1
for i in range(n) :
    ang = 2 * math.pi / n * i
    x, y = sin(ang) * 1000000, cos(ang) * 1000000
    print int(x), int(y)
