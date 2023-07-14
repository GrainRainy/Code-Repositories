#include <bits/stdc++.h>
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
const int N = 2e5 + 10;
LL n;
LL stk[N], top;

void div(LL u) {
	for (int i = 2; i * i <= u; ++ i) {
		while (!(u % i)) u /= i, stk[i] ++, top = max(top, (LL)i);
	}
	if (u != 1) stk[u] ++, top = max(top, u);
	return;
}

bool check(int u) {
	for (int i = 2, tmpCnt; i <= top; ++ i) {
		if (!stk[i]) continue;
		tmpCnt = 0;
		for (int j = i; j <= u; j *= i) {
			tmpCnt += u / j;
			if (tmpCnt >= stk[i]) break;
		}
		if (tmpCnt < stk[i]) return false;
	}
	return true;
}

int main() {
	input(n);
	for (int i = 1, tmp; i <= n; ++ i) input(tmp), div(tmp);
	int l = 1, r = 1e9, mid;
	while (l < r) {
		mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << endl;
	return 0;
}
