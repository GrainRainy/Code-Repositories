#include <bits/stdc++.h>
namespace IO {
    template <typename T> inline void input(T &x) {
        x = 0; char c = getchar();
        for (; !isdigit(c); c = getchar());
        for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
    }
}

using IO::input;
using namespace std;
const int N = 1e3 + 10;
int n, sd[N], st[N], f[N][N];

inline void upd(int &x, int y) { (x > y) and (x = y); }

int main() {
    input(n);
    memset(f, 0x3f, sizeof f);
    for (int i = 1; i <= n; ++ i) {
        input(st[i]), input(sd[i]);
        f[i][i] = st[i] * sd[i];
        st[i] += st[i - 1];
        sd[i] += sd[i - 1];
    }
    for (int len = 2; len <= n; ++ len) {
        for (int l = 1, r; l + len - 1 <= n; ++ l) {
            r = l + len - 1;
            for (int mid = l + 1; mid < r; ++ mid)
                upd(f[l][r], f[l][mid - 1] + f[mid + 1][r]
                            + (st[mid - 1] - st[l - 1]) * (sd[r] - sd[mid - 1])
                            + (st[r] - st[l - 1]) * (sd[mid] - sd[mid - 1]));
        }
    }
    cout << f[1][n] << endl;
    return 0;
}