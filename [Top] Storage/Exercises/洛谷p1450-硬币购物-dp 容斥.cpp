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

template <typename T> inline void output(T x, char ed = '\n') {
    if (x < 0) putchar('-'), x = -x;
    static short st[20], top;
    do st[++ top] = x % 10, x /= 10; while (x);
    while (top) putchar(st[top --] | '0');
    putchar(ed);
}

const int N = 1e5 + 10;
const int P = 4;

int c[P], d[P];
LL dp[N];

void init() {
    dp[0] = 1;
    for (int i = 1; i <= 4; ++ i) {
        for (int j = c[i]; j <= N; ++ j) {
            dp[j] += dp[j - c[i]];
        }
    }
}

void solve() {
    LL sum = 0, res = 0;
    for (int i = 1; i <= 4; ++ i) input(d[i]);
    input(sum);
    for (int i = 0; i <= 15; ++ i) {
        LL tmp = sum;
        int cnt = 0;
        for (int j = 1; j <= 4; ++ j) 
            if ((i >> (j - 1)) & 1) 
                tmp -= c[j] * (d[j] + 1), cnt ^= 1;
        if (tmp < 0) continue;
        if (!cnt) res += dp[tmp];
        else res -= dp[tmp];
    }
    return output(res), void();
}

int main() {
    for (int i = 1; i <= 4; i ++) input(c[i]);
    init();
    int t; input(t);
    while (t --) solve();
    return 0;
}
