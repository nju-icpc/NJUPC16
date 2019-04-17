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

struct point {
    double x, y;

    point(double x, double y) : x(x), y(y) {}
    point operator + (point rhs) { return {x + rhs.x, y + rhs.y}; }
    point operator - (point rhs) { return {x - rhs.x, y - rhs.y}; }
    point operator * (double k) { return {k * x, k * y}; }
    point rot() { return {-y, x}; }
    double operator * (point rhs) { return x * rhs.y - y * rhs.x; }
    double length() { return hypot(x, y); }
};

int n;
vector<point> pts;

double check(point vec) {
    vector<double> res;
    rep (i, n) 
        res.push_back(pts[i] * vec / vec.length());
    sort(range(res));
    double d1 = res[n/2-1];
    double d2 = res[n/2];
    return (d2 - d1) / 2.0;
}

double solve1() { // mid
    double ans = 0.0;
    rep (i, n) 
        rep (j, i) 
            ans = max(ans, check((pts[i] - pts[j]).rot()));
    return ans;
}

double solve2() { // parallel
    double ans = 0.0;
    rep (i, n) 
        rep (j, i) 
            ans = max(ans, check(pts[i] - pts[j]));
    return ans;
}

int main() {
    cin >> n;
    rep (i, n) {
        double x, y; cin >> x >> y;
        pts.emplace_back(x, y);
    }
    printf("%.9f\n", max(solve1(), solve2()));
    return 0;
}
