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

const int N = 20;
const int S = (1 << 18) + 10;
int n, m, k, u, v;
int a[N], rul[N][N];
LL ans, dp[S][N];

int count(int s) {
    int res = 0;
    while (s) { res += (s & 1), s >>= 1; }
    return res;
}

int main() {
    input(n), input(m), input(k);
    for (int i = 1; i <= n; ++ i) input(a[i]), dp[1 << i - 1][i] = a[i];
    for (int i = 1; i <= k; ++ i) {
        input(u), input(v);
        input(rul[u][v]);
    }

    for (int s = 0; s < (1 << n); ++ s) {
        for (int i = 1; i <= n; ++ i) {
            if (!(s & (1 << i - 1))) continue;
            for (int j = 1; j <= n; ++ j) {
                if (i == j) continue;
                if (!(s & (1 << j - 1))) continue;
                dp[s][i] = max(dp[s][i], dp[s - (1 << i - 1)][j] + a[i] + rul[j][i]);
            }
            if (count(s) == m) ans = max(ans, dp[s][i]);
        }
    }
    cout << ans << endl;
    return 0;
}
