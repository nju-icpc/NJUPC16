#include <bits/stdc++.h>
using namespace std;

const int EXIT_AC = 42;
const int EXIT_WA = 43;

FILE* judgemessage = NULL;

[[noreturn]] void wrong_answer(const char *err, ...) {
    va_list pvar;
    va_start(pvar, err);
    vfprintf(judgemessage, err, pvar);
    fprintf(judgemessage, "\n");
    exit(EXIT_WA);
}

[[noreturn]] void judge_error(const char *err, ...) {
    va_list pvar;
    va_start(pvar, err);
    if (!judgemessage) judgemessage = stderr;
    vfprintf(judgemessage, err, pvar);
    fprintf(judgemessage, "\n");
    assert(!"Judge Error");
}

int readint() {
    int ret;
    if ((cin >> ret).fail()) 
        wrong_answer("integer expected");
    return ret;
}

vector<uint64_t> s;

uint64_t target;
int pc = 0, pc_limit = 200;

[[noreturn]] void crash(const char *why) {
    fprintf(judgemessage, "NEMU crashed when executing instruction #%d\n", pc);
    fprintf(judgemessage, "%s\n", why);
    fprintf(judgemessage, "stack trace:\n");
    putc('[', judgemessage);
    for (int i = 0; i < s.size(); i++) {
        if (i) fprintf(judgemessage, ", ");
        fprintf(judgemessage, "%" PRIu64, s[i]);
    }
    fprintf(judgemessage, "]\n");
    wrong_answer("NEMU crashed");
}

const char *USAGE = "Usage: %s judge_in judge_ans feedback_dir [max_inst] < team_out";

int main(int argc, char *argv[]) {
    if (argc < 4) judge_error(USAGE, argv[0]);
    judgemessage = fopen((argv[3] + string("judgemessage.txt")).c_str(), "w");
    if (judgemessage == NULL) judge_error("fail to open judge_message file");
    if (argc > 4) pc_limit = atoi(argv[4]);
    if (pc_limit < 60 || pc_limit > 1000000) judge_error(USAGE, argv[0]);
    if ((ifstream(argv[1]) >> target).fail()) judge_error("fail to open input file");
    string inst;
    while (pc < pc_limit and cin >> inst) {
        pc++;
        for (char& ch : inst) ch = tolower(ch);
        if (inst == "p1") {
            s.push_back(1); 
        } else if (inst == "dup") {
            s.push_back(s.back());
        } else if (inst == "pop") {
            if (s.empty()) 
                crash("pop: attept to pop element when stack is empty");
            s.pop_back();
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
            if (s.back() != target)
                wrong_answer("result mismatch: expected %" PRIu64 ", found %" PRIu64,
                    target, s.back());
            if (cin >> inst) 
                wrong_answer("end instruction is not the last instruction");
            return EXIT_AC;
        } else {
            crash(("invalid instruction: " + inst).c_str());
        }
    }
    if (pc >= pc_limit) wrong_answer("PC limit exceeded (%d)", pc_limit);
    wrong_answer("no end instruction until the end of the program");
}
