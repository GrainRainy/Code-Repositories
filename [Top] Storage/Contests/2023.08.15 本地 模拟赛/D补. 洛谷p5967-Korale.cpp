#include <bits/stdc++.h>
#define fi first
#define se second
#define debug(x) cerr << #x << ' ' << x << endl;
namespace IO {
	template <typename T> inline void rd(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
	template <typename T> inline void ot(T x, char ed = '\n') {
		if (x < 0) putchar('-'), x = -x;
		static short st[30], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
}

using namespace IO;
using namespace std;
using LL = long long;
using PLI = pair<LL, int>;
const int N = 1e6 + 10;
const int LOGN = 20;
int n, k, a[N], b[N];
int cnt, stk[N]; LL val;
priority_queue<PLI, vector<PLI>, greater<PLI>> q;
int st[N][LOGN + 10];

int upd(int x, int y) { 
	if (a[x] ^ a[y]) return a[x] < a[y] ? x : y;
	return x < y ? x : y;
}

void pre() {
	int mx = log2(n);
	for (int i = 1; i <= n; ++ i) st[i][0] = i;
	for (int k = 1; k <= mx; ++ k) 
		for (int i = 1; i + (1 << k) - 1 <= n; ++ i)
			st[i][k] = upd(st[i][k - 1], st[i + (1 << k - 1)][k - 1]);
	return;			
}

int mn(int l, LL val) { 
	int mx = log2(n - l + 1), p = l - 1;
	for (int k = mx; ~k; -- k) {
		if (p + (1 << k) - 1 <= n and a[st[p][k]] > val)
			p = p + (1 << k) - 1;
	}
	if (p + 1 > n) return 0;
	return p + 1;
}

void dfs(int pos, LL val) {
	if (!val) {
		cnt --;
		if (!cnt) {
			for (int i = 1; i <= stk[0]; ++ i) 
				ot(stk[i], ' ');
			putchar('\n');
			exit(0);
		}
		return;
	}
	for (int i = pos + 1, tar; i <= n; ++ i) {
		tar = mn(i, val);
		if (!tar) return;
		stk[++ stk[0]] = tar;
		dfs(tar, val - a[tar]);
		stk[0] --;
	}
}

int main() {
	rd(n), rd(k);
	if (!(-- k)) return puts("0"), 0;
	for (int i = 1; i <= n; ++ i) rd(a[i]), b[i] = a[i];
	sort(b + 1, b + n + 1), q.push({b[1], 1});
	for (int i = 1; i <= k; ++ i) {
		auto t = q.top(); q.pop();
		if (t.fi == val) cnt ++;
		else cnt = 1, val = t.fi;
		if (t.se < n) {
			q.push({t.fi + b[t.se + 1], t.se + 1});
			q.push({t.fi + b[t.se + 1] - b[t.se], t.se + 1});
		}
	}
	ot(val, '\n');
	pre(), dfs(0, val);
	return 0;
}
