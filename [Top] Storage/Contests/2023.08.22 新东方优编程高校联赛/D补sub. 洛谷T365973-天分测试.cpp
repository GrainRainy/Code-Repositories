#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
using LL = long long;
const int N = 2e2 + 10;
int n, m, k; 
int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[8] = {1, -1, 1, 0, -1, 1, 0, -1};
string gph[N], s;
map<string, int> mp;

char hsh(int i, int j) {
	i = (i % n + n) % n;
	j = (j % m + m) % m;
	return gph[i][j];
}

string get(int x, int y, int dir) {
	string s;
	for (int i = 1; i <= k; ++ i) {
		s = s + hsh(x, y);
		x = x + dx[dir];
		y = y + dy[dir];
	}
	return s;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	if (n == m) k = n; // Ò»¾ä»°Öµ 30pts Äó  
	for (int i = 0; i < n; ++ i) cin >> gph[i];
	for (int i = 0; i < n; ++ i)
		for (int j = 0; j < m; ++ j)
			for (int a = 0; a < 8; ++ a)
				mp[get(i, j, a)] ++;
	LL sum = 0, cnt = 0;
	for (auto t : mp) sum += t.second, cnt += t.second * t.second;
	sum = sum * sum;
	return cout << cnt / __gcd(sum, cnt) << '/' << sum / __gcd(sum, cnt) << endl, 0;
}
