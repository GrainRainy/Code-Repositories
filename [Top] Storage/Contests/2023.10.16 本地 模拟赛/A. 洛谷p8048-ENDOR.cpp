#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 1e5 + 10;
const int K = 40 + 10;
int n, k, tot, lt, rt, pre, pos1, coldel;
char c;
struct Ant {
	int x, col, type;
	bool operator < (const Ant &t) const { return x < t.x; }
}ant[N];
double res[K], tmp[K], ans[K];

int main() {
	freopen("endor.in", "r", stdin);
	freopen("endor.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> k >> tot;
	for (int i = 1, a, b; i <= n; ++ i) {
		cin >> a >> b >> c;
		ant[i] = {a, b, 0};
		if (c == 'D') ant[i].type = 1, ans[b] += tot - a;
	}
	sort(ant + 1, ant + n + 1);
	for (int i = 1; i <= n; ++ i) {
		if (ant[i].type) {
			coldel = (coldel + ant[i].col) % k;
			if (!pre) { pre = i, pos1 = ant[i].x; continue; }
			for (int j = 0; j < k; ++ j)
				tmp[(j + ant[i].col) % k] = res[j];
			for (int j = 0; j < k; ++ j) res[j] = tmp[j];
			res[ant[i].col] += (double)(ant[i].x - ant[pre].x) / 2;
			pre = i;
		} else {
			for (int j = 0; j < k; ++ j)
				ans[(ant[i].col + j) % k] += res[j];
			ans[ant[i].col] += (double)(ant[i].x - ant[pre].x) / 2;
			ans[(ant[i].col + coldel) % k] += ant[i].x - (double)(ant[i].x - pos1) / 2;
		}
	}
	for (int i = 0; i < k; ++ i) printf("%.1lf\n", ans[i]);
	return 0;
}
