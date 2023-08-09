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

const int N = 2e7 + 10;
int n, k, p;
int b, c, d;
int ary[N], pre[N], sur[N];
int ans;

int main() {
    input(n), input(k), input(p);
    input(ary[1]), input(b), input(c), input(d);
    for (int i = 2; i <= n; ++ i) 
        ary[i] = ((LL)ary[i - 1] * b + c) % d;

    ary[n + 1] = 1;
    for (int i = 1; i <= n; ++ i) {
        if (i % k == 1) pre[i] = ary[i] % p;
        else pre[i] = (LL)pre[i - 1] * ary[i] % p;
    }
    for (int i = n; i >= 1; -- i) {
        if (i % k) sur[i] = (LL)sur[i + 1] * ary[i] % p;
        else sur[i] = ary[i] % p;
    }

    for (int i = 1; i <= n - k + 1; ++ i) {
        if (i % k == 1) ans ^= pre[i + k - 1];
        else ans ^= (LL)sur[i] * pre[i + k - 1] % p;
    }
    printf("%d\n", ans);
    return 0;
}
