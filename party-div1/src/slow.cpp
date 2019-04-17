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

int n;
LL x[512000], y[512000];

int main() {
    cin >> n;
    rep (i, n) cin >> x[i] >> y[i];
    LL ans = LLONG_MAX, ai, aj;
    rep (i, n) {
        LL minq = LLONG_MIN;
        rep (j, n) if (i != j and x[j] > x[i]) minq = max(minq, y[j]); 
        rep (j, n) if (i != j and y[j] >= minq) {
                LL cur = abs(x[i] - y[j]);
                if (cur < ans) {
                    ans = cur;
                    ai = i;
                    aj = j;
                }
            }
    }
    cerr << ai << ' ' << aj << endl;
    cout << ans << endl;
    return 0;
}

