#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int n, m;
char arr[128][128];
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

bool within(int x, int y) {
    return x >= 0 and x < n and y >= 0 and y < m;
}

bool test(int x, int y, int d, const char *str) {
    while (*str and within(x, y)) {
        if (*str != arr[x][y]) return false;
        x += dx[d]; y += dy[d];
        str++;
    }
    return *str == '\0';
}

int main() {
    cin >> n >> m;
    rep (i, n) rep (j, m) {
        string str; cin >> str;
        arr[i][j] = str[0];
    }
    int ans1 = 0, ans2 = 0;
    rep (i, n) rep (j, m) rep (d, 8) {
        ans1 += int(test(i, j, d, "COFFEE"));
        ans2 += int(test(i, j, d, "CHICKEN"));
    }
    printf("COFFEE x %d\n", ans1);
    printf("CHICKEN x %d\n", ans2);
    return 0;
}
