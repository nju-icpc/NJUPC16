#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(2, 1000, "n"); inf.readSpace();
    int m = inf.readInt(1, 10, "m"); inf.readEoln();
    for (int i = 0; i < n; i++) {
        set<int> ss;
        for (int j = 0; j < m; j++) {
            string s = inf.readToken();
            int val;
            if (s != "-") {
                val = atoi(s.c_str());
                ensuref(val > 0 and val < 300, "value out of range");
                ensuref(ss.count(val) == 0, "line %d, col %d, duplicate element", i, j);
                ss.insert(val);
            }
            if (j < m - 1) inf.readSpace(); else inf.readEoln();
        }
    }
    inf.readEof();
    return 0;
}

