ninf = -int(2e18)
n, k = map(int, input().split())
tot = 0
b = []
for _ in range(n) :
    w, h = map(int, input().split())
    tot += w * h
    b.append((h, w))
b.sort()
dp = [[ninf] * (n + 1) for _ in range(k + 1)]
dp[0][0] = 0
pre = [[0] * (n + 1) for _ in range(k + 1)]
for i in range(k) :
    for f in range(n) :
        cur = dp[i][f] + b[f][0] * b[f][1]
        for t in range(f+1, n+1) :
            if cur > dp[i+1][t] :
                dp[i+1][t] = cur
                pre[i+1][t] = f
            if t < n :
                cur += b[f][0] * b[t][1]
print(tot - dp[k][n])
