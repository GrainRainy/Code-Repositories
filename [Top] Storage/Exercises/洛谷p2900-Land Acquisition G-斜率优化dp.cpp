#include <iostream>
#include <cstring>
#include <algorithm>

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
using D = double;
using LL = long long;
const int N = 5e4 + 10;

int n, top;
struct Matrix {
	int x, y;
	bool operator < (const Matrix &t) const {
		return x == t.x ? y < t.y : x < t.x;
	}
}ary[N];
int q[N], head = 1, tail = 1;
LL dp[N]; 

inline D X(int i) { return (D)ary[i].y; }
inline D Y(int i) { return (D)dp[i]; }
inline D K(int i) { return -1.0 * ary[i].x; }
inline D slope(int a, int b) { return (Y(a) - Y(b)) / (X(a + 1) - X(b + 1)); }

int main() {
	input(n);
	for (int i = 1; i <= n; ++ i) input(ary[i].x), input(ary[i].y);
	sort(ary + 1, ary + 1 + n);
	for (int i = 1; i <= n; ++ i) {
		while (top and ary[i].y >= ary[top].y) top --;
		ary[++ top] = ary[i];
	}
	n = top;
	
	for (int i = 1; i <= n; ++ i) {
		while (head < tail and slope(q[head], q[head + 1]) >= K(i)) head ++;
		dp[i] = dp[q[head]] + (LL)ary[q[head] + 1].y * ary[i].x;
		while (head < tail and slope(q[tail], q[tail - 1]) <= slope(q[tail - 1], i)) tail --;
		q[++ tail] = i;
	}

	cout << dp[n] << endl;
	return 0;
}
