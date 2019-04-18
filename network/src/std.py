#!/usr/bin/python3
from heapq import *
n = 300000
m = int(input())
vis = [False] * n
adj = [[] for _ in range(n)]
q = []

def to_int(s) :
    tp = s[0]
    val = int(s[2:-1]) - 1
    if tp == 'I' : return val
    if tp == 'O' : return val + 200000
    return val + 100000

ans = 1000005
def visit(u) :
    if u >= 200000 :
        print(ans)
        exit(0)
    if vis[u] : return
    vis[u] = True
    for v, w in adj[u] :
        heappush(q, (-w, v))

for _ in range(m) :
    s = input().split()
    adj[to_int(s[0])].append((to_int(s[2]), int(s[3][1:-1])))

for i in range(100000) :
    visit(i)

while q :
    w, v = heappop(q)
    ans = min(ans, -w)
    visit(v)

assert 0
