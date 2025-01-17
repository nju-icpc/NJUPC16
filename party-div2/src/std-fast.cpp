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
vector<pair<LL, LL>> v1;
vector<LL> suf_max;
vector<tuple<int, LL, LL>> v2;

template <typename T>
auto lbound(T v1, T v2, LL x) {
    return lower_bound(v1, v2, x, [] (auto a, LL b) {
        return get<2>(a) < b;
    });
}

template <typename T>
LL mindif(int ex, T l, T r, LL v) {
    LL ret = LLONG_MAX;
    if (l == r) return ret;
    auto ptr = lbound(l, r, v);
    if (ptr != r) {
        auto cur = ptr;
        if (get<0>(*cur) == ex) cur++;
        if (cur != r) {
            ret = min(ret, llabs(get<2>(*cur) - v));
        }
    }
    if (ptr != l) {
        auto cur = prev(ptr);
        if (get<0>(*cur) == ex) {
            if (cur == l) {
                return ret;       
            } else {
                cur = prev(cur);
            }
        }
        ret = min(ret, llabs(get<2>(*cur) - v));
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    rep (i, n) {
        LL x, y; scanf("%lld%lld", &x, &y);
        v1.emplace_back(x, y);
    }
    sort(range(v1));
    suf_max.resize(n);
    suf_max.push_back(LLONG_MIN);
    for (int i = n; i; i--) suf_max[i-1] = max(suf_max[i], v1[i-1].second);
    rep (i, n) v2.emplace_back(i, v1[i].first, v1[i].second);
    sort(range(v2), [] (const auto& v1, const auto& v2) {
        return get<2>(v1) < get<2>(v2);
    });
    int lptr = 0, rptr = 0;
    LL ans = LLONG_MAX;
    while (lptr < n) {
        while (rptr < n and v1[rptr].first == v1[lptr].first) rptr++;
        LL miny = suf_max[rptr]; 
        for (int i = lptr; i < rptr; i++) {
            ans = min(ans, mindif(i, lbound(range(v2), miny), v2.end(),
                v1[i].first));
        }
        lptr = rptr;
    }
    cout << ans << endl;
    return 0;
}

