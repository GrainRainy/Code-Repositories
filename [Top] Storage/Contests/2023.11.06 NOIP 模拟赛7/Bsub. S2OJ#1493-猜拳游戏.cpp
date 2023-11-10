#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n, m, c[4], op[N], ck[N];
int bt[4][4] = {
	{ 0, 0, 0, 0 },
	{ 0, -1, 2, 1 },
	{ 0, 2, -1, 3 },
	{ 0, 1, 3, -1 }
};

void dfs(int pos) {
	if (pos > n) {
		for (int i = 1; i <= n; ++ i) ck[i] = op[i];
		for (int stp = 1; stp <= m; ++ stp) 
			for (int i = 1; i <= n >> stp; ++ i) {
				ck[i] = bt[ck[i * 2 - 1]][ck[i * 2]];
				if (!(~ck[i])) return;
			}
		for (int i = 1; i <= n; ++ i)
			cout << (op[i] == 1 ? 'R' : op[i] == 2 ? 'P' : 'S');
		cout << '\n', exit(0);
	}
	for (int t : {2, 1, 3})
		if (c[t] and (!(pos & 1) or t != op[pos - 1]))
			c[t] --, op[pos] = t, dfs(pos + 1), c[t] ++;
}

int main() {
	cin >> c[1] >> c[2] >> c[3];
	n = c[1] + c[2] + c[3], m = log2(n);
	if (c[1] == 0 and !(c[2] == 1 and c[3] == 1)) 
		return cout << "IMPOSSIBLE\n", 0;
	if (c[2] == 0 and !(c[1] == 1 and c[3] == 1)) 
		return cout << "IMPOSSIBLE\n", 0;
	if (c[3] == 0 and !(c[1] == 1 and c[2] == 1)) 
		return cout << "IMPOSSIBLE\n", 0;
	dfs(1);
	return cout << "IMPOSSIBLE\n", 0;
}
