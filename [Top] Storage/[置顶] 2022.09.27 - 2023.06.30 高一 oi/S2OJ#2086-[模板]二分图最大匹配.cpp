#include <iostream>
#include <cstring>
#include <algorithm>

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

const int N = 1e3 + 10;
const int M = 5e4 + 100;

int n, m, e;
// basic things
int head[N], idx;
struct Node{
    int nxt, to;
}edge[M << 1];
// graph
int match[N];
bool st[N];

inline void add(int a, int b){
    edge[++ idx].nxt = head[a];
    edge[idx].to = b;
    head[a] = idx;
}

bool find(int cur){
    for (int i = head[cur]; ~i; i = edge[i].nxt){
        int j = edge[i].to;
        if (st[j]) continue;
        st[j] = true;
        if (!match[j] or find(match[j])){
            match[j] = cur;
            return true;
        }
    }
    return false;
}

signed main(){
    memset(head, -1, sizeof head    );

    input(n), input(m), input(e);
    int tmpa, tmpb;
    for (int i = 1; i <= e; i ++){
        input(tmpa), input(tmpb);
        add(tmpa, tmpb);
    }
    // input
    int ans = 0;
    for (int i = 1; i <= n; i ++){
        memset(st, 0, sizeof st);
        if (find(i)) ans ++;
    }
    cout << ans << endl;
    return 0;
}