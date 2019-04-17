#include <bits/stdc++.h>
using namespace std;

vector<uint64_t> s;

void p1() {
    s.push_back(1);
    cout << "p1" << endl;
}

void add(int pos) {
    cout << "add" << ' ' << s.size() - pos - 1 << endl;
    s.back() += s[pos];
}

void sub(int pos) {
    cout << "sub" << ' ' << s.size() - pos - 1 << endl;
    s.back() -= s[pos];
}

void dup() {
    s.push_back(s.back());
    cout << "dup" << endl;
}

void end() {
    cout << "end" << endl;
}

void mul(int pos) {
    cout << "mul" << ' ' << s.size() - pos - 1 << endl;
    s.back() *= s[pos];
}

void construct(uint64_t cur) {
    if (cur == 1) p1(); 
    else {
        construct(cur >> 1);
        add(s.size() - 1);
        if (cur & 1) add(0);
    }
}

int main() {
    uint64_t val; cin >> val;
    if (val == 0) {
        cout << "p1\nsub 0\nend\n";
        return 0;
    }
    p1();
    construct(val);    
    end();
    return 0;
}
