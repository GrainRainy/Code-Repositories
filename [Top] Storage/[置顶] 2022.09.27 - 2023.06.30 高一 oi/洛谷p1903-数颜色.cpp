#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
using LL = long long;

template <typename T> inline void input(T &x){
    x = 0; char c = getchar();
    bool f = false;
    for (; !isdigit(c); c = getchar())
        f |= (c == '-');
    for (; isdigit(c); c = getchar())
        x = x * 10 + (c ^ '0');
    if (f) x = -x;
}

const int N = 2e5 + 10;
const int C = 2e5 + 10;
const int S = 1e6 + 100;

int n, m;
int nums[N];
int cq;
struct Query{
    int l, r;
    int id, t;
}q[N];
int cm;
struct Modify{
    int pos, x;
}mo[C];
// basic things
int len = 0, res = 0;
int ans[N], st[S];

inline int get(int a){
    return a / len;
}

inline bool cmp(const Query &a, const Query &b){
    if (get(a.l) ^ get(b.l)) return a.l < b.l;
    if (get(a.r) ^ get(b.r)) return a.r < b.r;
    return a.t < b.t;
} 

inline void add(int pos){
    if (!st[pos]) res ++;
    st[pos] ++;
}

inline void del(int pos){
    if (st[pos] == 1) res --;
    st[pos] --;
}

int main(){
    input(n), input(m);
    for (int i = 1; i <= n; i ++){
        input(nums[i]);
    }
    for (int i = 1; i <= m; i ++){
        char op[2]; int x, y;
        cin >> op; input(x), input(y);
        if (op[0] == 'Q') q[++ cq] = {x, y, cq, cm};
        else mo[++ cm] = {x, y};
    }
    // input
    len = cbrt((double) n * max(1, cm)) + 1;
    sort(q + 1, q + 1 + cq, cmp);

    int i = 1, j = 0;
    int t = 0; // tstamp;
    for (int k = 1; k <= cq; k ++){
        int id = q[k].id, l = q[k].l, r = q[k].r, tim = q[k].t;
        while (i > l) add(nums[-- i]);
        while (j < r) add(nums[++ j]);
        while (i < l) del(nums[i ++]);
        while (j > r) del(nums[j --]);

        while (t < tim){
            t ++;
            if (mo[t].pos >= i and mo[t].pos <= j){
                del(nums[mo[t].pos]);
                add(mo[t].x);
            }
            swap(nums[mo[t].pos], mo[t].x);
            }
        while (t > tim){
            if (mo[t].pos >= i and mo[t].pos <= j){
                del(nums[mo[t].pos]);
                add(mo[t].x);
            }
            swap(nums[mo[t].pos], mo[t].x);
            t --;
        }
        ans[id] = res;
    }

    for (int i = 1; i <= cq; i ++)
        cout << ans[i] << endl;
    return 0;
}
