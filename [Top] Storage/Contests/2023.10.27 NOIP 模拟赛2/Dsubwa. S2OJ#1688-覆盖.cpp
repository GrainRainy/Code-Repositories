#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << '\n';
using namespace std;
const int N = 1e5 + 10;
using ULL = unsigned long long;
const ULL base = 13331;
int n;
char s[N];
ULL pw[N] = {1}, hsh[N];

bool jg(int a, int b, int l) {
	ULL hsha = hsh[a + l - 1] - hsh[a - 1] * pw[l];
	ULL hshb = hsh[b + l - 1] - hsh[b - 1] * pw[l];
	return hsha == hshb;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> s + 1, n = strlen(s + 1);
	for (int i = 1; i <= n; ++ i) pw[i] = pw[i - 1] * base;
	for (int i = 1; i <= n; ++ i) {
		hsh[i] = hsh[i - 1] * base + (s[i] - 'a' + 1);
	}
	for (int i = 1, c; i <= n; ++ i) {
//	for (int i = 3, c; i <= 3; ++ i) {
		c = 0;
		for (int j = 1; j <= i; ++ j) {
			bool f = true;
			for (int k = j + 1; k <= i; ++ k) {
				bool ff = false;
				for (int a = max(1, k - j + 1); a <= k; ++ a)
					if (jg(a, 1, j)) { ff = true; break; }
				if (!ff) { f = false; break; }
			}
			if (f) c ++;
		}
		cout << c << '\n';
	}
	return 0;
}
