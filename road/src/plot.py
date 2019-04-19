#!/usr/bin/env python3
import matplotlib.pyplot as plt
import sys
plt.figure(figsize=(6, 6))
plt.xticks([])
plt.yticks([])
n = int(input())
points = []
maxv = minv = 0;
for _ in range(n) :
    x, y = map(int, input().split())
    maxv = max(maxv, x)
    maxv = max(maxv, y)
    minv = min(minv, x)
    minv = min(minv, y)
    points.append([x, y])
    plt.scatter(x, y, c='b', s=5)

tp, id1, id2 = map(int, input().split())
plt.scatter(points[id1][0], points[id1][1], c='r', s=5)
plt.scatter(points[id2][0], points[id2][1], c='r', s=5)

p1x, p1y, p2x, p2y = map(float, input().split())
plt.plot([p1x, p2x], [p1y, p2y])

plt.xlim(minv * 1.1, maxv * 1.1)
plt.ylim(minv * 1.1, maxv * 1.1)

plt.savefig(sys.argv[1]) 
