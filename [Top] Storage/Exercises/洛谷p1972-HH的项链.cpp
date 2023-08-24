#include <iostream>
#include <cstring>
#include <algorithm>

#define lowbit(x) ((x) & -(x))

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

const int N = 1e6 + 10;
int n, m;
int a[N], pos[N];
struct Query {
    int l, r;
    int id;

    bool operator < (const Query &t) const {
        return r < t.r;
    }
}q[N];
// basis 
int tr[N], ans[N];

void modify(int u, int val)  {
    for (; u <= n; u += lowbit(u)) {
        tr[u] += val;
    }
}

int query(int u) { // 1 ~ u
    int res = 0;
    for (; u; u -= lowbit(u)) {
        res += tr[u];
    }
    return res;
}

int main() {
    input(n);
    for (int i = 1; i <= n; ++ i) input(a[i]);
    input(m);
    for (int i = 1; i <= m; ++ i) {
        input(q[i].l), input(q[i].r);
        q[i].id = i;
    }
    // input 

    sort(q + 1, q + 1 + m);
    int p = 1;
    for (int i = 1; i <= m; ++ i) {
        for (int j = p; j <= q[i].r; ++ j) {
            if (pos[a[j]]) modify(pos[a[j]], -1);
            pos[a[j]] = j, modify(j, 1);
        }
        p = q[i].r + 1;
        ans[q[i].id] = query(q[i].r) - query(q[i].l - 1);
    }
    for (int i = 1; i <= m; ++ i) output(ans[i]);
    return puts("") & 0;
}
