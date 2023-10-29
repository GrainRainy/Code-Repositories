#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10;
int n, p = 3, fac[3] = {1, 1, 2}, ans;
char s[N];

int val(char s) { return s == 'B' ? 0 : s == 'R' ? 1 : 2; }
void upd(int &x, int y) { if ((x += y) >= p) x -= p; }
int C(int n, int m) { return n < m ? 0 : fac[n] * fac[m] * fac[n - m] % p; }
int lucas(int n, int m) { return !m ? 1 : C(n % p, m % p) * lucas(n / p, m / p) % p; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> s + 1;
	for (int i = 1; i <= n; ++ i) 
		upd(ans, lucas(n - 1, i - 1) * val(s[i]));
	n & 1 ? 0 : ans = (p - ans) % p;
	return cout << (!ans ? 'B' : ans == 1 ? 'R' : 'W') << '\n', 0;
}
