#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);
  int n = inf.readInt(1, 200000, "n"); inf.readEoln();
  for (int i = 1; i <= n; i++) {
    inf.readLong(2ll, 1000000000000ll, "x"); 
    if (i == n) inf.readEoln(); else inf.readSpace();
  }
  inf.readEof();
  return 0;
}
