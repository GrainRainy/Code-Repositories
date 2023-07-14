#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 5e5 + 10;
LL n, m, c[N], u, v;
set<int> gph[N];
map<set<int>, LL> Hash;
void solve() {
	Hash.clear();
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; ++ i)
        scanf("%lld", &c[i]), gph[i].clear();
    while (m --) {
        scanf("%lld%lld", &u, &v);
        gph[v].insert(u);
    }
    for (int i = 1; i <= n; i ++)
        if (gph[i].size()) Hash[gph[i]] += c[i];
    LL ans = 0;
    for (auto &t : Hash) {	
        if (ans) ans = __gcd(ans, t.second);
        if (!ans) ans = t.second;
    }
    printf("%lld\n", ans);
    return;
}

int main() {
    int t; scanf("%d", &t);
    while (t --) solve();
    return 0;
}
