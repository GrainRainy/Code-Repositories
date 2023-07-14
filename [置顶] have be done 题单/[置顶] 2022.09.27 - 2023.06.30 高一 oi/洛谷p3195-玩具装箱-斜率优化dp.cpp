#include <iostream>
#include <cstring>
#include <algorithm>

namespace IO {
	template <typename T> inline void input (T &x) {
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

const int N = 5e4 + 10;
int n, l, sum[N];
int q[N], head = 1, tail = 1;
double dp[N];

inline double A(int x) { return (double)sum[x] + x; }
inline double B(int x) { return A(x) + l + 1; }
inline double X(int x) { return B(x); }
inline double Y(int x) { return dp[x] + B(x) * B(x); }
inline double slope(int a, int b) { return (Y(b) - Y(a)) / (X(b) - X(a)); }

int main() {
	input(n), input(l);
	for (int i = 1; i <= n; ++ i) input(sum[i]), sum[i] += sum[i - 1];
	
	for (int i = 1; i <= n; ++ i) {
		while (head < tail and slope(q[head], q[head + 1]) < 2 * A(i)) head ++;
		dp[i] = dp[q[head]] + (A(i) - B(q[head])) * (A(i) - B(q[head]));
		while (head < tail and slope(q[tail - 1], q[tail]) > slope(q[tail - 1], i)) tail --;
		q[++ tail] = i;
	}
	cout << (LL)dp[n] << endl;
	return 0;
}
