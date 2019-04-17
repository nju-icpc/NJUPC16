#!/usr/bin/env python3
import matplotlib.pyplot as plt
import sys, random
n = int(sys.argv[1])
seed = int(sys.argv[2])

random.seed(seed)
print(n + n)
for _ in range(n) :
    x = random.randint(-1000000, 1000000)
    y = random.randint(200000, 1000000)
    print(x, y)
    print(x, -y)

