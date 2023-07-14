#include <bits/stdc++.h>
#define debug(x) cerr << #x << ' ' << x << endl;
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
using LL = long long;
const int N = 1e3 + 10;
int n, m, a[N];
LL sum, cnt;
bool st[N];

int main() {
	input(n), input(m);
	for (int i = 1; i <= n; ++ i) input(a[i]);
	sort(a + 1, a + n + 1); 
	for (LL s = 0; s < (1 << n); ++ s) {
		sum = 0;
		for (int i = 1; i <= n; ++ i) {
			if ((s >> (i - 1)) & 1) sum += a[i], st[i] = true;
			else st[i] = false;
		}
		if (sum > m) continue;
		for (int i = 1; i <= n; ++ i)
			if (!st[i]) {
				cnt += (m - sum < a[i]);
				break;
			}
	}
	printf("%d\n", cnt);
	return 0;
}
