#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

template <typename T> inline void input(T &x){
    x = 0; char c = getchar();
    bool f = false;
    for (; !isdigit(c); c = getchar())
        f |= (c == '-');
    for (; isdigit(c); c = getchar())
        x = x * 10 + (c ^ '0');
    if (f) x = -x;
}

const int N = 5e4 + 100;
const int M = 2e5 + 100;
const int S = 1e6 + 1000;

int n, m;
int nums[N];
struct Query{
    int l, r;
    int idx;
}q[M];
// basic things
int len, res;
int st[S];
int ans[M];
// mo algo

inline int get(int a){
    return a / len;
}

inline bool cmp(Query &a, Query &b){
    if (get(a.l) ^ get(b.l)) return a.l < b.l;
    else return a.r < b.r;
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    input(n);
    for (int i = 1; i <= n; i ++){
        input(nums[i]);
    }
    input(m);
    for (int i = 1; i <= m; i ++){
        input(q[i].l), input(q[i].r);
        q[i].idx = i;
    }
    // input
    len = max(1, (int)sqrt((double)n * n / m));
    sort(q + 1, q + 1 + m, cmp);

    int i = 1, j = 0;
    for (int k = 1; k <= m; k ++){
        int id = q[k].idx, l = q[k].l, r = q[k].r;

        while (i > l) add(nums[-- i]);
        while (j < r) add(nums[++ j]);
        while (i < l) del(nums[i ++]);
        while (j > r) del(nums[j --]);
        ans[id] = res;
    }

    for (int i = 1; i <= m; i ++){
        cout << ans[i] << endl;
    }
    return 0;
}