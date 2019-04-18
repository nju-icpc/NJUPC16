#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int h = inf.readInt(1, 100); inf.readSpace();
    int w = inf.readInt(1, 100); inf.readEoln();
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            inf.readToken("[A-Z]");
            if (j == w - 1) inf.readEoln();
            else inf.readSpace();
        }
    }
    inf.readEof();
    return 0;
}

