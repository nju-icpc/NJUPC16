ninf = -int(2e18)
n, k = map(int, raw_input().split())
tot = 0
b = []
for _ in range(n) :
    w, h = map(int, raw_input().split())
    tot += w * h
    b.append((h, w))
b.sort()

wps = [0]
for h, w in b :
    wps.append(wps[-1] + w)

dp = [[ninf] * (n + 1) for _ in range(k + 1)]
dp[0][0] = 0
pre = [[0] * (n + 1) for _ in range(k + 1)]

def solve(j, l, r, vl, vr) :
    if l >= r : return
    mid = (l + r) >> 1
    for i in range(vl, min(mid, vr)) :
        nv = dp[j-1][i] + (wps[mid] - wps[i]) * b[i][0]
        if nv > dp[j][mid] :
            dp[j][mid] = nv
            pre[j][mid] = i
    solve(j, l, mid, vl, pre[j][mid]+1)
    solve(j, mid+1, r, pre[j][mid], vr)

for i in range(1, k+1) :
    solve(i, 0, n + 1, 0, n + 1)
print tot - dp[k][n]
