#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int t, n, tl, ml, tr, mr, a[N << 1], pos[N][2];
int top;
bool op[N << 1];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++ i) op[i] = pos[i][0] = pos[i][1] = 0;
	for (int i = 1; i <= n << 1; ++ i) {
		cin >> a[i];
		pos[a[i]][(bool)pos[a[i]][0]] = i;
	}
	op[top = 1] = 1, op[n << 1] = 1;
	ml = pos[a[1]][1] - 1, mr = pos[a[1]][1] + 1, tl = 2, tr = n << 1;
	while (tl <= ml or mr <= tr) {
		if (tl < ml and a[tl] == a[ml]) {
			top ++;
			op[top] = op[(n << 1) - top + 1] = 1;
			tl ++, ml --;
		} else if (tl <= ml and mr <= tr and a[tl] == a[mr]) {
			top ++;
			op[top] = 1, op[(n << 1) - top + 1] = 0;
			tl ++, mr ++;
		} else if (mr <= tr and tl <= ml and a[tr] == a[ml]) {
			top ++;
			op[top] = 0, op[(n << 1) - top + 1] = 1;
			tr --, ml --;
		} else if (mr < tr and a[tr] == a[mr]) {
			top ++;
			op[top] = op[(n << 1) - top + 1] = 0;
			tr --, mr ++;
		} else break;
	}
	if (top == n) {
		for (int i = 1; i <= n << 1; ++ i) cout << (op[i] ? 'L' : 'R');
		return cout << '\n', void();
	}
	op[top = 1] = 0, op[n << 1] = 1;
	ml = pos[a[n << 1]][0] - 1, mr = pos[a[n << 1]][0] + 1, tl = 1, tr = (n << 1) - 1;
	while (tl <= ml or mr <= tr) {
		if (tl < ml and a[tl] == a[ml]) {
			top ++;
			op[top] = op[(n << 1) - top + 1] = 1;
			tl ++, ml --;
		} else if (tl <= ml and mr <= tr and a[tl] == a[mr]) {
			top ++;
			op[top] = 1, op[(n << 1) - top + 1] = 0;
			tl ++, mr ++;
		} else if (mr <= tr and tl <= ml and a[tr] == a[ml]) {
			top ++;
			op[top] = 0, op[(n << 1) - top + 1] = 1;
			tr --, ml --;
		} else if (mr < tr and a[tr] == a[mr]) {
			top ++;
			op[top] = op[(n << 1) - top + 1] = 0;
			tr --, mr ++;
		} else break;
	}
	if (top == n) {
		for (int i = 1; i <= n << 1; ++ i) cout << (op[i] ? 'L' : 'R');
		return cout << '\n', void();
	}
	return cout << -1 << '\n', void();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t --) solve();
	return 0;
} 
