#!/usr/bin/env python3
import matplotlib.pyplot as plt
import sys

plt.figure(figsize=(6, 6))
plt.xticks([])
plt.yticks([])

n = int(input())
pts = [tuple(map(int, input().split())) for _ in range(n)]
x, y = zip(*pts)
minv, maxv =  -1, max(max(x), max(y), 0) + 1
margin = (maxv - minv) * 0.1
minv -= margin
maxv += margin
p1, p2 = map(int, open(sys.argv[1]).read().split())

plt.axhline(0, color='grey', lw=0.5)
plt.axvline(0, color='grey', lw=0.5)
plt.axvspan(minv, x[p1], color=(0.5, 0.5, 0.5, 0.2))
plt.axhspan(minv, y[p2], color=(0.5, 0.5, 0.5, 0.2))

for xx, yy in pts :
    plt.scatter(xx, yy, c='b', s=10)

plt.scatter(x[p1], y[p1], c='r', s=50)
plt.scatter(x[p2], y[p2], c='g', s=50)

plt.plot([x[p1], x[p1]], [minv, maxv], c='black', lw=2)
plt.plot([minv, maxv], [y[p2], y[p2]], c='black', lw=2)

plt.text(0.5 * margin, minv - 0.5 * margin, 
    (' xv=%d ' % x[p1]) + (' yv=%d ' % y[p2]) + 
    (' ans=%d ' % abs(x[p1] - y[p2])))
plt.xlim(minv, maxv)
plt.ylim(minv, maxv)

plt.savefig(sys.argv[2]) 
