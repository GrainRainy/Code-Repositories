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

const int N = 1e6 + 10;
int n, a, b, c;
int q[N], head = 1, tail = 1;
LL dp[N], sum[N];

inline D A(int i) { return (D)dp[i] - (D)a * sum[i] * sum[i]; }
inline D B(int i) { return (D)dp[i] + (D)a * sum[i] * sum[i] - (D)b * sum[i]; }
inline D X(int i) { return (D)sum[i]; }
inline D Y(int i) { return (D)B(i); }
inline D slope(int a, int b) { return (Y(a) - Y(b)) / (X(a) - X(b)); }

int main() {
	input(n), input(a), input(b), input(c);
	for (int i = 1; i <= n; ++ i) input(sum[i]), sum[i] += sum[i - 1];
	
	for (int i = 1; i <= n; ++ i) {
		while (head < tail and slope(q[head], q[head + 1]) > 2 * a * sum[i]) head ++;
		dp[i] = B(q[head]) - 2 * a * sum[i] * sum[q[head]] + a * sum[i] * sum[i] + b * sum[i] + c;
		while (head < tail and slope(q[tail], q[tail - 1]) <= slope(i, q[tail - 1])) tail --;
		q[++ tail] = i;
	}
	cout << dp[n] << '\n';
	return 0;
}
