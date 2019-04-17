#!/usr/bin/env python2
import random, sys
random.seed(int(sys.argv[1]))
print '%d' % random.randint(0, 2 ** 32 - 1)
