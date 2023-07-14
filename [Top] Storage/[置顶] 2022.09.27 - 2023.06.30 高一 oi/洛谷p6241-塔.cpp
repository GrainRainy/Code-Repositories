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

LL q;
// basis
LL mx, delta, tmp, ans[70], top;

void solve() {
    top = mx = 1;

    input(q);
    if (q == 1) return puts("1"), void();
    ans[1] = 1;
    while (mx < q) {
        ans[++ top] =  1;
        mx <<= 1;
    }
    delta = mx - q, tmp = top - 1;
    output(top);
    while (delta) {
        if (delta & 1) ans[tmp] = 2;
        tmp --;
        delta >>= 1;
    }
    for (int i = 1; i <= top; i ++) 
        output(ans[i], ' '), output(i);
    return;
}

int main() {
    int t; input(t);
    while (t --) solve();
    return 0;
}
