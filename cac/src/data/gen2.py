#!/usr/bin/python2
import sys, random, string
dx = [1, 1, 1, 0, -1, -1, -1, 0]
dy = [-1, 0, 1, 1, 1, 0, -1, -1]

h = int(sys.argv[1])
w = int(sys.argv[2])
ntrys = int(sys.argv[3])
random.seed(int(sys.argv[4]))

g = [[''] * w for _ in range(h)]

def inrange(x, y) :
    return x >= 0 and y >= 0 and x < h and y < w

for _ in range(ntrys) :
    x = random.randrange(0, h)
    y = random.randrange(0, w)
    d = random.randrange(0, 8)
    s = random.choice(['COFFEE', 'CHICKEN'])
    for ch in s :
        if g[x][y] == '' : g[x][y] = ch
        x += dx[d]
        y += dy[d]
        if not inrange(x, y) :
            break

for i in range(h) :
    for j in range(w) :
        if g[i][j] == '' :
            g[i][j] = random.choice('COFFEECHICKEN' + string.uppercase)

print h, w
for row in g :
    print ' '.join(row)
