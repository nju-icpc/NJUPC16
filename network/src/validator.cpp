#include "testlib.h"
using namespace std;

vector<int> adj[100005];

int readnode(string types) {
    string str = inf.readToken("[" + types + "]\\[[1-9][0-9]{0,5}\\]");
    int tp;
    if (str[0] == 'I') tp = 0;
    else if (str[0] == 'O') tp = 1;
    else if (str[0] == 'H') tp = 2;
    else ensure(0);
    int id = atoi(str.c_str() + 2);
    ensure(1 <= id and id <= 100000);
    return tp * 100000 + id;
}

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int m = inf.readInt(1, 1000000, "m"); inf.readEoln();
    while (m--) {
        int x = readnode("IH"); inf.readSpace(); inf.readToken("->"); inf.readSpace();
        int y = readnode("OH"); inf.readSpace();
        adj[x].push_back(y);
        string str = inf.readToken("\\([1-9][0-9]{0,6}\\)");
        int w = atoi(str.c_str() + 1);
        ensure(x != y and 0 < w and w <= 1000000);
        inf.readEoln();
    }
    inf.readEof();
    return 0;
}

