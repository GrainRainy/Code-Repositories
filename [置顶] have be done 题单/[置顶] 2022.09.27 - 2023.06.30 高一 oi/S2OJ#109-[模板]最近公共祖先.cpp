#include <iostream>
#include <cstring>
#include <queue>
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

template <typename T> inline void output(T x, char ed = '\n'){
    if (x < 0) putchar('-'), x = -x;
    static short st[64], top;
    do st[++ top] = x % 10, x /= 10; while (x);
    while (top) putchar(st[top --] | '0');
    putchar(ed);
}

const int N = 5e5 + 100;
const int K = 20;

int n, m, s;
// basic things
int head[N], idx;
struct node{
    int nxt, to;
}edge[N << 1];
// graph
queue<int> q;
int depth[N], father[N][K + 10];
// lca

inline void add(int a, int b){
    edge[++ idx].nxt = head[a];
    edge[idx].to = b;
    head[a] = idx;
}

void bfs(int root){
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0;
    depth[root] = 1; q.push(root);

    while (q.size()){
        auto cur = q.front(); q.pop();

        for (int i = head[cur]; ~i; i = edge[i].nxt){
            int j = edge[i].to;
            if (depth[j] > depth[cur] + 1){
                depth[j] = depth[cur] + 1;
                q.push(j);

                father[j][0] = cur;
                for (int k = 1; k <= K; k ++)
                    father[j][k] = father[father[j][k - 1]][k - 1];
            }
        }
    }
}

inline int query(int a, int b){
    if (depth[a] < depth[b]) swap(a, b);
    for (int k = K; k >= 0; k --){
        if (depth[father[a][k]] >= depth[b]) a = father[a][k];
    }
    if (a == b) return b;
    for (int k = K; k >= 0; k --){
        if (father[a][k] != father[b][k]){
            a = father[a][k];
            b = father[b][k];
        }
    }
    return father[a][0];
}

int main(){
    memset(head, -1, sizeof head);

    input(n), input(m), input(s);
    int tmpa, tmpb;
    for (int i = 1; i <= n - 1; i ++){
        input(tmpa), input(tmpb);
        add(tmpa, tmpb), add(tmpb, tmpa);
    }
    bfs(s);
    while (m --){
        input(tmpa), input(tmpb);
        // cout << query(tmpa, tmpb) << endl;
        output(query(tmpa, tmpb));
    }
    return 0;
}