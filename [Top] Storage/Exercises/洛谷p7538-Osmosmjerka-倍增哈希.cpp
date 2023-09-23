#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int N = 5e2 + 10;
const int LOGK = 15;
const int BASE = 13331;
const int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dy[] = {1, -1, 1, 0, -1, 1, 0, -1};
int n, m, mxk; LL k;
string g[N];
ULL p[LOGK];
ULL hsh[LOGK + 5][N][N][8];
vector<ULL> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	k = min(k, (LL)n * m / __gcd(n, m));
	mxk = log2(k);
	for (int i = 0; i < n; ++ i) cin >> g[i];
	p[0] = BASE;
	for (int i = 1; i <= mxk; ++ i) p[i] = p[i - 1] * p[i - 1];
	for (int i = 0; i < n; ++ i)
		for (int j = 0; j < m; ++ j)
			for (int d = 0; d < 8; ++ d)
				hsh[0][i][j][d] = g[i][j] - 'a' + 1;
	for (int a = 1; a <= mxk; ++ a)
		for (int i = 0; i < n; ++ i)
			for (int j = 0; j < m; ++ j)
				for (int d = 0; d < 8; ++ d) {
					int nx = ((i + dx[d] * (1 << a - 1)) % n + n) % n;
					int ny = ((j + dy[d] * (1 << a - 1)) % m + m) % m;
					hsh[a][i][j][d] = hsh[a - 1][i][j][d] * p[a - 1] + hsh[a - 1][nx][ny][d];
				}
	for (int i = 0; i < n; ++ i)
		for (int j = 0; j < m; ++ j)
			for (int d = 0; d < 8; ++ d) {
				int x = i, y = j;
				ULL val = 0;
				for (int a = mxk; ~a; -- a) {
					if (k >> a & 1) {
						val = val * p[a] + hsh[a][x][y][d];
						x = ((x + dx[d] * (1 << a)) % n + n) % n;
						y = ((y + dy[d] * (1 << a)) % m + m) % m;
					}
				}
				s.push_back(val);
			}
	sort(s.begin(), s.end());
	LL cnt = 0, sum = 0;
	for (int i = 0; i < s.size(); ++ i) {
		if (i and s[i] == s[i - 1]) cnt ++;
		else sum += cnt * cnt, cnt = 1;
	}
	sum += cnt * cnt, cnt = (LL)s.size() * s.size();
	LL g = __gcd(cnt, sum);
	return cout << sum / g << '/' << cnt / g << '\n', 0;
}
