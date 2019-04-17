#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 100, "n"); inf.readSpace();
    int a = inf.readInt(1, 100, "a"); inf.readSpace();
    int b = inf.readInt(1, 100, "b"); inf.readEoln();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += inf.readInt(1, 100, "x");
        if (i < n - 1) inf.readSpace(); else inf.readEoln();
    }
    ensure(a < b and b < sum);
    inf.readEof();
    return 0;
}

