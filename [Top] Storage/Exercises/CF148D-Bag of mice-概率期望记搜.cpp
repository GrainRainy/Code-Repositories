#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

template <typename T> inline void input(T &x) {
    x = 0; char c = getchar();
    bool f = false;
    for (; !isdigit(c); c = getchar())
        f |= (c == '-');
    for (; isdigit(c); c = getchar())
        x = x * 10 + (c ^ '0');
    if (f) x = -x;
}

const int N = 1e3 + 10;
int w, b;
double dp[N][N];

double dfs(int cw, int cb) {
    if (!cw) return 0; if (!cb) return 1;
    double &t = dp[cw][cb];
    if (t) return t;
    t += (double)cw / (cw + cb);
    if (cb == 2) 
        t += (double)cb / (cw + cb) * (cb - 1) / (cw + cb - 1) * dfs(cw - 1, cb - 2);
    if (cb >= 3) 
        t += (double)cb / (cw + cb) * (cb - 1) / (cw + cb - 1) * 
             ((double)cw / (cw + cb - 2) * dfs(cw - 1, cb - 2) + (double)(cb - 2) / (cw + cb - 2) * dfs(cw, cb - 3));
    return t;
}

int main() {
    input(w), input(b);
    printf("%.9lf\n", dfs(w, b));
    return 0;
}
