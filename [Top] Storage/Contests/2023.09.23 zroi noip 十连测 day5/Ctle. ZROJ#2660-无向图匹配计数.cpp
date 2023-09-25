#include <bits/stdc++.h>
using namespace std;
const int N = 2e2 + 10;
const int M = N << 1;
int n, m, c1, c2;
struct Save { int a, b; }e[M];
unordered_map<int, bool> mp;
long long ans;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> c1 >> c2;
	for (int i = 1; i <= m; ++ i) cin >> e[i].a >> e[i].b;
	for (int s = 0; s < 1 << m; ++ s) {
		mp.clear();
		bool ab = true;
		for (int i = 1; i <= m; ++ i)
			if ((s >> i - 1) & 1) {
				if (mp.find(e[i].a) != mp.end()) { ab = false; break; }
				if (mp.find(e[i].b) != mp.end()) { ab = false; break; }	
				mp[e[i].a] = mp[e[i].b] = true;
			}
		if (!ab) continue;
		ans ++;
	}
	return cout << ans << '\n', 0;
}
