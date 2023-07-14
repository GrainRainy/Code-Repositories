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

int main() {
	int n; input(n);
	int cnt = 0;
	for (int i = 1, tmp; i <= n; ++ i) {
		input(tmp);
		while (!(tmp & 1)) tmp /= 2, cnt ++;
	}
	cout << cnt << endl;
	return 0;
}
