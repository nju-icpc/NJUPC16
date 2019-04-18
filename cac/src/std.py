#!/usr/bin/python2
h, w = map(int, raw_input().split())
g = [''.join(raw_input().split()) for _ in range(h)]
s = g[:] + map(''.join, zip(*g))

for i in range(h) :
    x = i
    y = 0
    sc = ''
    while x < h and y < w :
        sc += g[x][y]
        x += 1
        y += 1
    s.append(sc)

for i in range(w) :
    x = 0
    y = i
    sc = ''
    while x < h and y < w :
        sc += g[x][y]
        x += 1
        y += 1
    s.append(sc)

for i in range(h) :
    x = i
    y = w - 1
    sc = ''
    while x < h and y >= 0 :
        sc += g[x][y]
        x += 1
        y -= 1
    s.append(sc)

for i in range(w) :
    x = 0
    y = i
    sc = ''
    while x < h and y >= 0 :
        sc += g[x][y]
        x += 1
        y -= 1
    s.append(sc)

ans = [0, 0]
for i, st in enumerate(['COFFEE', 'CHICKEN', 'EEFFOC', 'NEKCIHC']) :
    ans[i & 1] += sum(map(lambda x : x.count(st), s))

print 'COFFEE x', ans[0]
print 'CHICKEN x', ans[1]
