#include <bits/stdc++.h>

namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
	template <typename T> inline void output(T x, char ed = '\n') {
		if (x < 0) putchar('-'), x = -x;
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
}

using namespace IO;
using namespace std;

const int N = 500 + 10;
const int K = 10;
int n, k, c;
int sit[N][K];
int stk[N], top;
bool st[N];
priority_queue<int, vector<int>, greater<int>> q;
map<int, bool> mp;

void dfs(int mx) {
	if (top == k) {
		int ans = 0, tmp = 0;
		for (int j = 1; j <= k; ++ j) {
			tmp = 0;
			for (int i = 1; i <= top; ++ i) tmp = max(tmp, sit[stk[i]][j]);
			ans += tmp;
		}
		while (q.size() >= c) q.pop();
		q.push(ans);
		return;
	}
	for (int i = mx; i <= n; ++ i) {
		if (!st[i]) {
			st[i] = true;
			stk[++ top] = i;
			dfs(i + 1);
			top --;
			st[i] = false;
		}
	}
	return;
}

int main() {
//	freopen("olympic3.in", "r", stdin);
//	freopen("test.out", "w", stdout);
	input(n), input(k), input(c);
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= k; ++ j) 
			input(sit[i][j]), mp[sit[i][j]] = true;
	
	if (mp.size() == 1) return output(sit[1][1] * k, '\n'), 0;
	dfs(1);
	cout << q.top() << endl;
}

