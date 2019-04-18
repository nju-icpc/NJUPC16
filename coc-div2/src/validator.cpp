#include "testlib.h"
using namespace std;

typedef long long LL;

LL f(LL x) {
    if (x == 1) return 6;
    if (x == 2) return 7;
    return f(x - 2) + f(x - 1);
}

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 30); inf.readSpace();
    LL m = inf.readLong(1, f(n)); inf.readEoln();
    inf.readEof();
    return 0;
}

