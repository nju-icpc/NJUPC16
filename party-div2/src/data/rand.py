#!/usr/bin/env python2
import sys, random
n = int(sys.argv[1])
random.seed(int(sys.argv[2]))
print n
for _ in range(n) :
    print random.randint(0, 1000000000), random.randint(0, 1000000000)
