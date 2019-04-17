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
    int ans = INT_MAX;
    cin >> n;
    rep (i, n) cin >> x[i] >> y[i];
    rep (i, n) rep (j, n) if (i != j) {
        rep (k, n) if (x[k] > x[i] and y[k] > y[j]) goto cont;
        ans = min(ans, abs(x[i] - y[j]));
        cont:;
    }
    cout << ans << endl;
    return 0;
}

