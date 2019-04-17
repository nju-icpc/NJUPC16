#include <bits/stdc++.h>
using namespace std;

int readint() {
    int ret;
    if ((cin >> ret).fail()) {
        cerr << "unexpected input" << endl;
        exit(EXIT_FAILURE);
    }
    return ret;
}

vector<uint64_t> s;

int pc = 0;

void crash(string why) {
    cerr << "NEMU crashed when executing instruction #" << pc << endl;
    cout << why << endl;
    cout << "stack trace:" << endl;
    cout << '[';
    for (int i = 0; i < s.size(); i++) {
        if (i) cout << ", ";
        cout << s[i];
    }
    cout << ']' << endl;
    exit(EXIT_FAILURE);
}

int main() {
    string inst;
    while (pc < 60 and cin >> inst) {
        pc++;
        for (char& ch : inst) ch = tolower(ch);
        if (inst == "p1") {
            s.push_back(1); 
        } else if (inst == "dup") {
            s.push_back(s.back());
        } else if (inst == "pop") {
            if (s.empty()) 
                crash("pop: attept to pop element when stack is empty");
        } else if (inst == "swap") {
            if (s.size() < 2) 
                crash("swap: the size of stack is less than 2");
            swap(s.back(), s.rbegin()[1]);
        } else if (inst == "add") {
            int pos = readint();
            if (pos < 0 || pos >= s.size())
                crash("add: index out of range"); 
            s.back() += s.rbegin()[pos]; 
        } else if (inst == "sub") {
            int pos = readint();
            if (pos < 0 || pos >= s.size())
                crash("sub: index out of range"); 
            s.back() -= s.rbegin()[pos]; 
        } else if (inst == "mul") {
            int pos = readint();
            if (pos < 0 || pos >= s.size())
                crash("mul: index out of range"); 
            s.back() *= s.rbegin()[pos];
        } else if (inst == "end") {
            if (s.empty()) 
                crash("end: attept to output element when stack is empty");
            cout << s.back() << endl;
            return 0;
        } else {
            crash("invalid instruction: " + inst);
        }
    }
    cerr << "wrong answer" << endl;
    return EXIT_FAILURE;
}
