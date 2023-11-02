#include <bits/stdc++.h>
using namespace std;
using ULL = unsigned long long;
const int N = 2e6 + 10;
const ULL base = 13331;
int n, ansl, ansr;
char s[N];
ULL hsh[N], pw[N] = {1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> s + 1;
	if (!(n & 1)) return puts("NOT POSSIBLE") & 0;
	for (int i = 1; i <= n; ++ i) pw[i] = pw[i - 1] * base;
	for (int i = 1; i <= n; ++ i) hsh[i] = hsh[i - 1] * base + s[i] - 'A' + 1;
	for (int i = 1, sl; i <= n; ++ i) {
		sl = n - 1 >> 1;
		if (i <= sl) {
			ULL hsha = hsh[i - 1] * pw[sl - i + 1] + hsh[sl + 1] - hsh[i] * pw[sl - i + 1];
			ULL hshb = hsh[n] - hsh[n - sl] * pw[sl];
			if (hsha == hshb and ansl and hsha != hsh[ansr] - hsh[ansl - 1] * pw[sl]) return puts("NOT UNIQUE") & 0;
			if (hsha == hshb) ansl = n - sl + 1, ansr = n;
		} else {
			ULL hsha = hsh[sl];
			ULL hshb = (hsh[i - 1] - hsh[sl] * pw[i - sl - 1]) * pw[n - i] + hsh[n] - hsh[i] * pw[n - i];
			if (hsha == hshb and ansl and hsha != hsh[ansr] - hsh[ansl - 1] * pw[sl]) return puts("NOT UNIQUE") & 0;
			if (hsha == hshb) ansl = 1, ansr = sl;
		}
	}
	if (!ansl and !ansr) return puts("NOT POSSIBLE") & 0;
	for (int i = ansl; i <= ansr; ++ i) cout << s[i];
	return cout << '\n', 0;
}
