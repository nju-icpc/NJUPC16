#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); i++)
#define range(x) begin(x), end(x)
typedef long long LL;

int n;
LL x[200005];
mt19937 gen(time(NULL));

void stub() {
    double tsec = (double) clock() / CLOCKS_PER_SEC; 
    if (tsec >= 1.85) {
        printf("NO\n");
        exit(0);
    }
}

void check(LL f) {
    int cnt = 0;
    rep (i, n) if (x[i] % f == 0) cnt++;
    if (cnt + cnt >= n) {
        printf("YES\n");
        exit(0);
    }
}

int main() {
    scanf("%d", &n);
    rep (i, n) scanf("%lld", x + i);
    while (true) {
        LL num = x[gen() % n];
        for (LL f = 2; f * f <= num; f++) {
            if (num % f) continue;
            stub();
            check(f); check(num / f);
        }
    }
    return 0;
}
