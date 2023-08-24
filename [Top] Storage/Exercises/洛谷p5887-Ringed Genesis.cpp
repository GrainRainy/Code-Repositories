#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

template <typename T> inline void input(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

const int N = 1e6 + 10;
int n, m, k;
bool color[N];
int cnt, tmp, ans;

int main() {
	input(n), input(m), input(k);
	cnt = __gcd(n, k);
	for (int i = 1; i <= m; ++ i) {
		input(tmp);
		color[tmp % cnt] = true;
	}
	for (int i = 0; i < cnt; ++ i) {
		if (!color[i]) ans += n / cnt;
	}
	cout << ans << endl;
	return 0;
} 
