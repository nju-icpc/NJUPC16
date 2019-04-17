#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 100, "n"); inf.readSpace();
    int m = inf.readInt(1, 100, "m"); inf.readEoln();
    bool flag = false;
    while (n--) {
        for (int i = 0; i < m; i++) {
            if (inf.readInt(0, 100, "h") != 0) flag = true;
            if (i < m - 1) inf.readSpace(); else inf.readEoln();
        }
    }
    ensuref(flag, "all numbers are zero!");
    inf.readEof();
    return 0;
}

