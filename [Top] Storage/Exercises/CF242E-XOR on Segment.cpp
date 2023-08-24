#include <iostream>
#include <cstring>
#include <algorithm>

#define lson (u << 1)
#define rson (u << 1 | 1)
#define __DEBUG__ puts("__DEBUG__");

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
    while (top) putchar(st[top -- ] | '0');
    putchar(ed);
}

const int N = 1e5 + 10;
const int LOGN = 20;
int n, m;
int a[N];
int op, qx, qy, qz;
// basis 
int tl[N << 2], tr[N << 2], tag[N << 2];
int sum[N << 2][LOGN + 10];
// Segment Tree 

void PushUp(int u) {
    for (int i = 0; i < LOGN; ++ i) 
        sum[u][i] = sum[lson][i] + sum[rson][i];
    return;
}

void PushDown(int u) {
    if (!tag[u]) return;
    for (int i = 0; i < LOGN; ++ i) {
        if ((tag[u] >> i) & 1) {
            sum[lson][i] = (tr[lson] - tl[lson] + 1) - sum[lson][i];
            sum[rson][i] = (tr[rson] - tl[rson] + 1) - sum[rson][i];
        }
    }
    tag[lson] ^= tag[u], tag[rson] ^= tag[u];
    tag[u] = 0;
    return;
}

void build(int u, int l, int r) {
    tl[u] = l, tr[u] = r;
    if (l == r) {
        for (int i = 0; i < LOGN; ++ i) 
            sum[u][i] = (a[l] >> i) & 1;
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid), build(rson, mid + 1, r);
    PushUp(u);
}

void modify(int u, int l, int r, int val) {
    if (l > tr[u] or r < tl[u]) return;
    if (l <= tl[u] and r >= tr[u]) {
        for (int i = 0; i < LOGN; ++ i) 
            if ((val >> i) & 1) 
                sum[u][i] = (tr[u] - tl[u] + 1) - sum[u][i];
        tag[u] ^= val;
        return;
    }
    PushDown(u);
    modify(lson, l, r, val), modify(rson, l, r, val);
    PushUp(u);
}

LL query(int u, int l, int r) {
    if (l > tr[u] or r < tl[u]) return 0;
    if (l <= tl[u] and r >= tr[u]) {
        LL res = 0, p = 1;
        for (int i = 0; i < LOGN; ++ i) {
            res += p * sum[u][i];
            p <<= 1;
        }
        return res;
    }
    PushDown(u);
    return query(lson, l, r) + query(rson, l, r);
}

int main() {
    input(n);
    for (int i = 1; i <= n; i ++) input(a[i]);
    
    build(1, 1, n);
    input(m);
    while (m --) {
        input(op), input(qx), input(qy);
        if (op == 1) output(query(1, qx, qy));
        if (op == 2) input(qz), modify(1, qx, qy, qz);
    }
    return 0;
}
