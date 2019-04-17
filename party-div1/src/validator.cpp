#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(2, 300000, "n"); inf.readEoln();
    while (n--) {
        inf.readLong(0ll, 1000000000'000000000, "x"); inf.readSpace();
        inf.readLong(0ll, 1000000000'000000000, "y"); inf.readEoln();
    }
    inf.readEof();
    return 0;
}
