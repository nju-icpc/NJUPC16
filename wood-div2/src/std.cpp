#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); i++)
#define Rep(i, n) for (int i = 1; i <=int(n); i++)
#define range(x) begin(x), end(x)
#ifdef __LOCAL_DEBUG__
# define _debug(fmt, ...) fprintf(stderr, "[%s] " fmt "\n", __func__, \
  ##__VA_ARGS__)
#else
# define _debug(...) ((void) 0)
#endif

typedef long long LL;
typedef unsigned long long ULL;

int n, k;
vector<pair<LL, LL>> b;
LL tot;
LL dp[8192][8192];
int pre[8192][8192];

int main() {
    scanf("%d%d", &n, &k);
    rep (i, n) {
        LL w, h; scanf("%lld%lld", &w, &h);
        tot += w * h;
        b.emplace_back(h, w);
    }
    sort(b.begin(), b.end());
    rep (i, k + 1) rep (j, n + 1) dp[i][j] = LLONG_MIN;
    dp[0][0] = 0;
    for (int i = 0; i < k; i++) {
        for (int f = 0; f < n; f++) {
            LL cur = dp[i][f] + b[f].first * b[f].second;
            for (int t = f + 1; t <= n; t++) {
                if (cur > dp[i+1][t]) {
                    dp[i+1][t] = cur;
                    pre[i+1][t] = f;
                }
                if (t < n) cur += b[f].first * b[t].second;
            }
        }
    }
    cout << tot - dp[k][n] << endl;
    vector<int> trans;
    int cur = n, kk = k;
    while (cur) {
        trans.push_back(cur);
        cur = pre[kk][cur];
        kk--;
    }
    assert(kk == 0);
    reverse(range(trans));
    for (int x : trans) cerr << x << ' ' ;
    cerr << endl;
    return 0;
}
