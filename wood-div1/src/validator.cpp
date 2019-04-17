#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);
  int n = inf.readInt(1, 5000, "n"); inf.readSpace();
  int k = inf.readInt(1, 2000, "k"); inf.readEoln();
  ensuref(k <= n, "k(%d) > n(%d)!", k, n);
  while (n--) {
    inf.readInt(1, 10000000, "w"); inf.readSpace();
    inf.readInt(1, 10000000, "h"); inf.readEoln();
  }
  inf.readEof();
  return 0;
}
