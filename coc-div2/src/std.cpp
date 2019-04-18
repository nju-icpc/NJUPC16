#include <bits/stdc++.h>
using namespace std;

string f(int x) {
    if (x == 1) return "COFFEE";
    if (x == 2) return "CHICKEN";
    return f(x - 2) + f(x - 1);
}

int main() {
    int x, y; cin >> x >> y;
    string s = f(x).substr(y - 1);
    if (s.size() >= 10) {
        cout << s.substr(0, 10) << endl;
    } else {
        cout << s << endl;
    }
    return 0;
}
