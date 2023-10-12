#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m, k, d;
char s[N], tp[N];
int lsf[N], rsf[N], dst[N], res[N], tmp[N], top;

void qpow(int *a, int b) {
	for (int i = 0; i < n; ++ i) res[i] = a[i];
	while (b) {
		if (b & 1) {
			for (int i = 0; i < n; ++ i) tp[i] = s[res[i]];
			for (int i = 0; i < n; ++ i) s[i] = tp[i];
		}
		for (int i = 0; i < n; ++ i) tmp[i] = res[res[i]];
		for (int i = 0; i < n; ++ i) res[i] = tmp[i];
		b >>= 1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> s >> m; 
	n = strlen(s);
	for (int i = 0; i < n; ++ i) {
		lsf[i] = i + 1 == n ? 0 : i + 1;
		rsf[i] = i - 1 == -1 ? n - 1 : i - 1;
	}
	while (m --) {
		cin >> k >> d; top = 0;
		for (int i = 0; i < d; ++ i) 
			for (int j = i; j < k; j += d) dst[top ++] = j;
		for (int i = top; i < n; ++ i) dst[i] = i;		
		for (int i = 0; i < n; ++ i) tmp[i] = dst[lsf[i]];
		for (int i = 0; i < n; ++ i) dst[i] = tmp[i];
		qpow(dst, n - k + 1), qpow(rsf, n - k + 1);
		cout << s << '\n';
	}
	return 0;
}
