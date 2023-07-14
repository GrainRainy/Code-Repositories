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
using namespace std;
using namespace IO;
using D = double;
using LD = long double;
using LL = long long;

const int N = 2e4 + 10;
int n, sum[N], dis[N], tot;
int q[N], head = 1, tail = 1;
LL ans = 0x3f3f3f3f3f3f3f3f;

inline int X(int i) { return (D)sum[i]; }
inline int Y(int i) { return (D)sum[i] * dis[i]; }
inline int K(int i) { return dis[i]; }
inline LD slope(int a, int b) { return (LD)(Y(a) - Y(b)) / (LD)(X(a) - X(b)); }

int main() {
	input(n);
	for (int i = 1; i <= n; ++ i) 
		input(sum[i]), sum[i] += sum[i - 1], input(dis[i]);
	for (int i = n; i >= 1; -- i)
		tot += sum[i] * dis[i], dis[i] += dis[i + 1];

	for (int i = 1; i <= n; ++ i) {
		while (head < tail and slope(q[head], q[head + 1]) >= K(i)) head ++;
		ans = min(ans, (LL)(-1 * Y(q[head]) - K(i) * X(i) + (LL)sum[q[head]] * dis[i] + tot));
		while (head < tail and slope(q[tail - 1], q[tail]) <= slope(q[tail - 1], i)) tail --;
		q[++ tail] = i;
	}
	cout << ans << endl;
	return 0;
}
