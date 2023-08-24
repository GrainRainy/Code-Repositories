#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>

#define fi first
#define se second

using namespace std;
using LL = long long;
using PII = pair<int, int>;

template <typename T> inline void input(T &x) {
    x = 0; char c = getchar();
    bool f = false;
    for (; !isdigit(c); c = getchar())
        f |= (c == '-');
    for (; isdigit(c); c = getchar())
        x = x * 10 + (c ^ '0');
    if (f) x = -x;
}

const int N = 310;
const int S = 2e6;
const int P = 30;
int n, m, t, top;
PII dots[P], stt, ed;
map<PII, int> mp;
// basis 
int TmpDist[N][N];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
bool st[N][N];
// bfs 
char gph[N][N];
int dist[P][P], dp[S][P], ans = 0;
// dp 

int count(int s) {
    int res = 0;
    while (s) {
        if (s & 1) res ++;
        s >>= 1;
    }
    return res;
}

void bfs(int root) {
    memset(TmpDist, 0, sizeof TmpDist);
    memset(st, 0, sizeof st);
    queue<PII> q;
    TmpDist[dots[root].fi][dots[root].se] = 0, q.push(dots[root]);
    
    while (q.size()) {
        auto t = q.front(); q.pop();
        if (st[t.fi][t.se]) continue;
        st[t.fi][t.se] = true;
        if (gph[t.fi][t.se] != '#' and gph[t.fi][t.se] != '.') {
                dist[root][mp[{t.fi, t.se}]] = TmpDist[t.fi][t.se];
            }
        for (int i = 0; i < 4; ++ i) {
            int tox = t.fi + dx[i], toy = t.se + dy[i];
            if (tox < 1 or tox > n or toy < 1 or toy > m) continue;
            if (gph[tox][toy] == '#') continue;
            TmpDist[tox][toy] = TmpDist[t.fi][t.se] + 1;
            q.push({tox, toy});
        }
    }
}

int main() {
    input(n), input(m), input(t);
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= m; ++ j) {
            cin >> gph[i][j];
            if (gph[i][j] == 'S') stt = {i, j};
            if (gph[i][j] == 'G') ed = {i, j};
            if (gph[i][j] == 'o') dots[++ top] = {i, j}, mp[dots[top]] = top;
        }
    }
    
    dots[top + 1] = stt, mp[stt] = top + 1;
    dots[top + 2] = ed, mp[ed] = top + 2;

    memset(dist, 0x3f, sizeof dist);
    for (int i = 1; i <= top + 2; ++ i) bfs(i);
    if (dist[top + 1][top + 2] > t) return puts("-1") & 0;

    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= top; ++ i) {
    	dp[(1 << i - 1)][i] = dist[top + 1][i];
	}
    
    for (int s = 1; s < (1 << top); ++ s) {
        for (int i = 1; i <= top; ++ i) {
            if (!(s & (1 << i - 1))) continue;
            for (int j = 1; j <= top; ++ j) {
                if (i == j) continue;
                if (!(s & (1 << j - 1))) continue;
                if (dist[i][j] == 0x3f3f3f3f) continue;
                dp[s][i] = min(dp[s][i], dp[s - (1 << i - 1)][j] + dist[i][j]);
            }
            
            if (dp[s][i] + dist[i][top + 2] <= t) ans = max(ans, count(s));
        }
    }
    cout << ans << endl;
    return 0;
}
