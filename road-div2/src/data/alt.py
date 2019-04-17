#!/usr/bin/env python3
import matplotlib.pyplot as plt
import sys, random
n = int(sys.argv[1])
gp = int(sys.argv[2])
seed = int(sys.argv[3])

random.seed(seed)
print(n)
for _ in range(n) :
    x = random.randint(-1000000, 1000000)
    y = random.randint(gp, 1000000)
    if _ & 1 :
        print(x, y)
    else :
        print(x, -y)

