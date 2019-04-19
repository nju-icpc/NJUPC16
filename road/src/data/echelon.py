#!/usr/bin/env python3
import sys
n = int(sys.argv[1])
print(n + n)
for i in range(n) :
    print(i * 5000, -1000000 + i * 2000)
    print(i * 5000, 1000000 - i * 2000)
