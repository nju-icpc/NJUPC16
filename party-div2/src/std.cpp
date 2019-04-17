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
int x[10240], y[10240];

int main() {
    cin >> n;
    rep (i, n) cin >> x[i] >> y[i];
    int ans = INT_MAX, ai, aj;
    rep (i, n) {
        int minq = INT_MIN;
        rep (j, n) if (i != j and x[j] > x[i]) minq = max(minq, y[j]); 
        rep (j, n) if (i != j and y[j] >= minq) {
                int cur = abs(x[i] - y[j]);
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

