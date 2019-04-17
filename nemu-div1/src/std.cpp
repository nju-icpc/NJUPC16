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

int main() {
    uint64_t val; cin >> val;
    if (val == 0) {
        cout << 
            "p1\n"
            "dup\n"
            "sub 1\n"
            "end\n";
        return 0;
    } else if (val == 2) {
        cout << 
            "p1\n"
            "add 0\n"
            "end\n";
        return 0;
    } else if (val == 15) {
        cout << 
            "p1\n"
            "dup\n"
            "add 1\n"
            "add 1\n"
            "dup\n"
            "add 2\n"
            "add 2\n"
            "mul 1\n"
            "swap\n"
            "pop\n"
            "end\n";
        return 0;
    } else if (-val == 1) {
        cout <<
            "p1\n"
            "dup\n"
            "add 1\n"
            "swap\n"
            "sub 1\n"
            "end\n";
        return 0;
    }
    p1();
    for (int i = 2; i <= 8; i++) {
        dup();
        add(0);
    }
    vector<uint64_t> cur;
    while (val) {
        cur.push_back(val & 7);
        val >>= 3;
    }
    reverse(cur.begin(), cur.end());
    p1(); if (cur[0] > 1) add(cur[0] - 2);
    for (int i = 1; i < cur.size(); i++) {
        mul(7);
        if (cur[i]) add(cur[i]-1); 
    }
    end();
    return 0;
}
