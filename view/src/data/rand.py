#!/usr/bin/python2
import sys, random
h = eval(sys.argv[1])
w = eval(sys.argv[2])
random.seed(int(sys.argv[3]))
pz = float(sys.argv[4])
print h, w
for _ in range(h):
    t = []
    for _ in range(w): 
        t.append(random.randint(0, 100))
        if random.uniform(0, 1) < pz :
            t[-1] = 0
    print ' '.join(map(str, t))
