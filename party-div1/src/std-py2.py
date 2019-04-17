#!/usr/bin/env python2
inf = 1000000000000000000
n = int(input())
v1 = sorted([map(int, raw_input().split()) for _ in range(n)])
v2 = sorted([(i, x, y) for i, (x, y) in enumerate(v1)], 
    key=lambda x : x[2])

def lbound(l, r, x) :
    while l < r :
        m = (l + r) >> 1
        if v2[m][2] < x :
            l = m + 1
        else :
            r = m
    return l

def mindif(ex, l, r, v) :
    ret = inf
    if l == r : return ret
    ptr = lbound(l, r, v)
    if ptr != r :
        cur = ptr
        if v2[cur][0] == ex : cur += 1
        if cur != r :
            ret = min(ret, abs(v2[cur][2] - v))
    if ptr != l :
        cur = ptr - 1
        if v2[cur][0] == ex :
            if cur == l :
                return ret
            else :
                cur -= 1
        newval = abs(v2[cur][2] - v)
        ret = min(ret, newval)
    return ret

suf_max = [0] * n + [-inf]
for i in range(n, 0, -1) :
    suf_max[i-1] = max(suf_max[i], v1[i-1][1])

lptr = rptr = 0
ans = inf

while lptr < n :
    while rptr < n and v1[rptr][0] == v1[lptr][0] : rptr += 1
    miny = suf_max[rptr]
    for i in range(lptr, rptr) :
        ans = min(ans, mindif(i, lbound(0, n, miny), n, v1[i][0]))
    lptr = rptr

print ans

