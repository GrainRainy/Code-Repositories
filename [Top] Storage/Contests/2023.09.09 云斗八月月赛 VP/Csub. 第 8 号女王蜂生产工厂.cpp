#include <bits/stdc++.h>
namespace IO {
	#ifdef __LINUX__
	#define getchar() getchar_unlocked()
	#endif
	#ifdef __WINDOWS__
	#define getchar() _getchar_nolock()
	#endif
	template <typename T> inline void rd(T &x) {
		x = 0; char c = getchar(); bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
}
using namespace IO;
using namespace std;
using LL = long long;
unsigned long long a, c, x;
int q, k;
LL totans, ans;

namespace Read{
	int cnt = 0; unsigned long long X;
	unsigned long long read(){
		if(++ cnt <= k) { IO::rd(X); return X;}
		else {X ^= X << 13; X ^= X >> 17; X ^= X << 5; return X = (X + a) % c;}
	}
}

int main() {
	rd(q), rd(k), rd(a), rd(c);
	for(int i = 1; i <= q; i ++){
		x = Read :: read();
		LL mx = log2(x), cnt = 0;
		for (int j = 0; j <= mx; ++ j) {
			if ((x >> j) & 1) cnt ++;
			else ans += (cnt + 1) * cnt >> 1, cnt = 0; 
		}
		ans += cnt * (cnt + 1) >> 1;
		totans ^= i * ans, ans = 0;
	}
	return cout << totans << '\n', 0;
}

