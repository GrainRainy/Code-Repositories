#include <bits/stdc++.h>
#define DEBUG cerr << "-- DEBUG --\n";
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 3e2 + 10;
const int M = 1e5 + 10;
int n, m, v[M], a[N], s[N];
vector<int> tmp;
unordered_map<int, int> del;
map<vector<int>, bool, greater<vector<int>>> ans;

template <typename T> inline void rd(T &x) {
	x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

template <typename T> inline void ot(T x, char ed = '\n') {
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

int main() {
	rd(n);
	for (int i = 1; i <= n * (n - 1) / 2; ++ i) rd(v[i]);
	sort(v + 1, v + n * (n - 1) / 2 + 1);
	for (int i = 2; i < n; ++ i) {
		del.clear();
		for (int j = 1; j <= i; ++ j) s[j + 1] = v[j];
		a[2] = v[i + 1] - s[3] + s[2] >> 1, a[1] = s[2] - a[2];
		if (a[1] <= 0) continue;
		for (int j = 3; j <= i + 1; ++ j) {
			a[j] = s[j] - a[1];
			for (int k = 2; k < j; ++ k) del[a[j] + a[k]] ++;
		}
		int top = i + 1;
		del[a[2] + a[3]] --;
		for (int j = i + 2; j <= n * (n - 1) / 2; ++ j) {
			while (j <= n * (n - 1) / 2 and del[v[j]] > 0) del[v[j]] --, j ++;
			if (j > n * (n - 1) / 2) break;
			a[++ top] = v[j] - a[1];
			for (int k = 2; k < top; ++ k) del[a[top] + a[k]] ++;
		}
		if (top != n) continue;
		tmp.clear();
		for (int i = 1; i <= n; ++ i) tmp.push_back(a[i]);
		ans[tmp] = true;
	}
	ot(ans.size());
	for (auto t : ans) {
		for (auto tmp : t.first) ot(tmp, ' ');
		putchar('\n');
	}
	return 0;
}
