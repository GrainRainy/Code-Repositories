#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
}

using namespace IO;
using namespace std;

const int N = 40;
int n, m;
int fa[N], siz[N], all;
vector<int> v;
map<vector<int>, double> mp;

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx != fy) fa[fy] = fx, siz[fx] += siz[fy];
}

vector<int> insert(vector<int> v, int x, int y) {
	v.insert(lower_bound(v.begin(), v.end(), v[x] + v[y]), v[x] + v[y]);
	v.erase(v.begin() + x), v.erase(v.begin() + y);
	return v;
}

void init() {
	all = n * (n - 1) / 2;
	for (int i = 1; i <= n; ++ i) fa[i] = i, siz[i] = 1;
}

double dp(vector<int> v) {
    if(mp.count(v)) return mp[v];
    int tot = v.size(), ne = 0;
    if(tot == 1) return mp[v] = 0;
    for(int i = 0; i < tot; i++) ne += v[i] * (v[i] - 1) / 2;
    ne = all - ne;
    double ans = (double)all / ne;
    for(int i = 0; i < tot; i++)
        for(int j = 0; j < i; j++)
            ans += (double)v[i] * v[j] / ne * dp(insert(v, i, j));
    return mp[v] = ans;
}

int main() {
    while(~scanf("%d %d", &n, &m)) {
    	v.clear(); mp.clear();
	    all = n * (n - 1) / 2;
	    for(int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
	    for(int i = 1, a, b; i <= m; i++) 
	        cin >> a >> b, merge(a, b);
	    for(int i = 1; i <= n; i++) 
	        if(fa[i] == i) v.push_back(siz[i]);
	    sort(v.begin(), v.end());
	    printf("%.6lf\n", dp(v));
	}
    return 0;
}
