#include <bits/stdc++.h>
#include <ctime>
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
const int N = 1e2 + 10;
int n, m, pre[N];
char name[N], hate[6][N], ans[N];
bool st[N], st2[N];
int sum, cnt;
int stk[N];
double bg;

void dfs(int pos) {
	if ((clock() - bg) / CLOCKS_PER_SEC > 0.9) { puts("0.00"); exit(0);}
	if (pos == n + 1) {
		for (int i = 1; i <= n; ++ i) st2[i] = false;
		for (int i = 1; i < pos; ++ i)
			if (pre[stk[i]] and !st2[pre[stk[i]]]) return;
			else st2[stk[i]] = true;
		sum ++;
		for (int i = 1; i <= n; ++ i) ans[i] = name[stk[i]];
		for (int i = 1; i <= m; ++ i)
			for (int j = 1; j <= n; ++ j) {
				int posa = j - 1, posb = 0;
				while (posb < strlen(hate[i] + 1) and ans[posa + 1] == hate[i][posb + 1])
					posa ++, posb ++;
				if (posb == strlen(hate[i] + 1)) return cnt ++, void();
			}
		return;
	}
	for (int i = 1; i <= n; ++ i) {
		if (st[i]) continue;
		stk[pos] = i;
		st[i] = true;
		dfs(pos + 1);
		st[i] = stk[pos] = 0;
	}
}

int main() {
	bg = clock();
	input(n);
	for (int i = 1; i <= n; ++ i) input(pre[i]);
	cin >> name + 1;
	input(m);
	for (int i = 1; i <= m; ++ i) cin >> hate[i] + 1;
	dfs(1);
	printf("%.2lf", (double)1 - (double)cnt / sum);
	return 0;
}
