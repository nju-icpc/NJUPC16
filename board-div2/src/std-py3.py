#!/usr/bin/python3
import itertools

n, m = map(int, input().split())

def read(x) :
    if x == '-' : return -1
    return int(x)

first = [500 for _ in range(m)]
jyy_str = input()
score = []
for _ in range(1, n) :
    x = list(map(read, input().split()))
    cnt = 0
    tot = 0
    for t in range(m) :
        if x[t] >= 0 :
            first[t] = min(first[t], x[t])
            cnt += 1
            tot += x[t]
    score.append((-cnt, tot))

jyy = []
for i, t in enumerate(list(map(read, jyy_str.split()))) :
    if t >= 0 :
        jyy.append([i, t])

jyy.sort(key = lambda k : k[1])

for i in reversed(range(1, len(jyy))) :
    jyy[i][1] -= jyy[i-1][1]

bf = 0
bestfs = 100000000
for x in itertools.permutations(jyy) :
    used = 0
    tot = 0
    cnt = 0
    for i, t in x :
        used += t
        tot += used
        if used <= first[i] :
            cnt += 1
    bf = max(bf, cnt)
    bestfs = min(bestfs, tot)

rk = 0
for tup in score : 
    if tup < (-len(jyy), bestfs) :
        rk += 1

print(bf, rk + 1)
