#!/usr/bin/python2
n, m = map(int, raw_input().split())
a = [ map(int, raw_input().split()) for _ in range(n) ]
for row in a :
    print ''.join(map(lambda x : '.#'[x > 0], row))

mw = max(map(max, a))
assert mw > 0
print 

mat = [['.'] * m for _ in range(mw)]
for i in range(m) :
    mv = 0
    for j in range(n) :
        mv = max(mv, a[j][i])
    for j in range(mw) :
        mat[j][i] = '.#'[j < mv]
for row in reversed(mat) :
    print ''.join(row)

print 

mat = [['.'] * n for _ in range(mw)]
for i in range(n) :
    mv = 0
    for j in range(m) :
        mv = max(mv, a[i][j])
    for j in range(mw) :
        mat[j][i] = '.#'[j < mv]
for row in reversed(mat) :
    print ''.join(row)

