#!/usr/bin/env python2
n = input()
x, y = zip(*[map(int, raw_input().split()) for _ in range(n)])

ans = 1000000000
for i in range(n) :
    minq = 0
    for j  in range(n) :
        if i != j and x[j] > x[i] : minq = max(minq, y[j])
    for j in range(n) :
        if i != j and y[j] >= minq :
                ans = min(ans, abs(x[i] - y[j]))

print ans
