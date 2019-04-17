#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define Rep(i, n) for (int i = 1; i <=int(n); i++)

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(2, 80, "n"); inf.readEoln();
    ensuref(n % 2 == 0, "n is not even!");
    set<pair<int, int>> sp;
    for (int i = 0; i < n; i++) {
        int x = inf.readInt(-1000000, 1000000, "x"); inf.readSpace();
        int y = inf.readInt(-1000000, 1000000, "y"); inf.readEoln();
        sp.emplace(x, y);
    }
    ensuref((int)sp.size() == n, "some points coincide!");
    inf.readEof();
    return 0;
}
