#include "testlib.h"
#include <cstdint>
#include <sstream>
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    istringstream iss(inf.readWord()); inf.readEoln();
    uint64_t u64;
    if ((iss >> u64).fail() || !iss.eof()) 
        ensuref(0, "invalid input");
    inf.readEof();
    return 0;
}

