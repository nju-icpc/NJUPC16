#!/usr/bin/python2
import sys, random
n = int(sys.argv[1])
xl = int(sys.argv[2])
xr = int(sys.argv[3])
yl = int(sys.argv[4])
yr = int(sys.argv[5])
random.seed(int(sys.argv[6]))
print n
for _ in range(n) :
    print random.randint(xl, xr), random.randint(yl, yr)
