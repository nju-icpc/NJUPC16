#include "testlib.h"
using namespace std;

typedef long long LL;
LL lf[100] = {0, 6, 7};

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    for (int i = 3; i <= 80; i++) lf[i] = lf[i-1] + lf[i-2];
    int T = inf.readInt(1, 1000, "T"); inf.readEoln();
    for (int t = 0; t < T; t++) {
        int n = inf.readInt(1, 500, "n"); inf.readSpace();
        LL s = inf.readLong(1ll, 1000000000000ll, "s"); inf.readEoln();
        if (n <= 70) ensuref(s <= lf[n], "s > lf[n]: T = %d, s = %lld, limit = %lld", t, s, lf[n]);
    }
    inf.readEof();
    return 0;
}

