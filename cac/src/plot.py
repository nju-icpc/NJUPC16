#!/usr/bin/env python3
import matplotlib.pyplot as plt
import matplotlib.patches as mp
import sys

for _ in range(2): 
    x1, y1, x2, y2 = map(int, input().split())
    plt.plot([x1, x1, x2, x2, x1], [y1, y2, y2, y1, y1])

plt.savefig(sys.argv[1]) 
