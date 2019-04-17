#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(2, 10000, "n"); inf.readEoln();
    while (n--) {
        inf.readInt(0, 1000000000, "x"); inf.readSpace();
        inf.readInt(0, 1000000000, "y"); inf.readEoln();
    }
    inf.readEof();
    return 0;
}
