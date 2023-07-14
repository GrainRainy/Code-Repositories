#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
int n, m;
char s[N], sas[N], sbs[N];
int ary[N], cnt;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	cin >> s;
	if (n == m) {
		int sum = 0;
		for (int i = 0; i < m; ++ i)
			if (s[i] == '(') sum ++;
			else sum --;
		if (!sum) cout << 1 << endl;
		else cout << 0 << endl;
	} else if (n <= 20) {
		for (int l = 0, r; l <= n - m; ++ l) {
			r = n - m;
			for (int sa = 0; sa < (1 << l); ++ sa) {
				for (int sb = 0, sum; sb < (1 << r); ++ sb) {
					sum = 0;
					for (int i = 0; sa >> i; i ++) 
						if ((sa >> i) & 1) sum ++, sas[i] = '1';
						else sum --, sas[i] = '0';
					for (int i = 0; i < m; ++ i)
						if (s[i] == '(') sum ++;
						else sum --;
					for (int i = 0; sb >> i; ++ i)
						if ((sb >> 1) & 1) sum ++;
						else sum --;
					if (sum == 0) cnt = (cnt + 1) % MOD;
				}
			}
		}
		cout << 0 << endl;
	} else cout << 0 << endl;
	return 0;
}
