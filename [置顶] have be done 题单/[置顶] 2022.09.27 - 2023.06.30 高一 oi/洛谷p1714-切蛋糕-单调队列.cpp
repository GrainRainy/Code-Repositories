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

const int N = 5e5 + 10;
int n, m, ary[N];
int q[N], head, tail, ans;

int main() {
	input(n), input(m);
	for (int i = 1; i <= n; ++ i) input(ary[i]);
	
}
