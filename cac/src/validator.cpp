#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    set<int> sx, sy;
    for (int i = 0; i < 2; i++) {
        int x1 = inf.readInt(0, 1000000000, "x1"); inf.readSpace();
        int y1 = inf.readInt(0, 1000000000, "y1"); inf.readSpace();
        int x2 = inf.readInt(0, 1000000000, "x2"); inf.readSpace();
        int y2 = inf.readInt(0, 1000000000, "y2"); inf.readEoln();
        sx.insert(x1); sx.insert(x2);
        sy.insert(y1); sy.insert(y2);
        ensure(x1 < x2 and y1 < y2);
    }
    ensure(sx.size() == 4 and sy.size() == 4);
    inf.readEof();
    return 0;
}

