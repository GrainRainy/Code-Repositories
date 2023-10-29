#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	} 
	template <typename T> inline void output(T x, char ed = '\n') {
		if (x < 0) putchar('-'), x = -x;
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
}

using namespace IO;
using namespace std;
using PII = pair<int, int>;
const int N = 2e5 + 10;
int n, ary[N];
map<PII, int> mp;

int get(int u, int pos) {
	if (mp.find({u, pos}) != mp.end()) return mp[{u, pos}];
	if ((pos << 1) > n) return mp[{u, pos}] = pos;
	int v = ary[pos << 1], w = ary[pos << 1 | 1];
	if (u < v and u < w) return mp[{u, pos}] = pos;
	if (v < u and v < w) return mp[{u, pos}] = get(u, pos << 1);
	if (u < v) return mp[{u, pos}] = min(get(u, pos << 1), get(u, pos << 1 | 1));
	return mp[{u, pos}] = get(v, pos << 1) < get(v, pos << 1 | 1) ? get(u, pos << 1 | 1) : get(u, pos << 1);
}

int main() {
	input(n); ary[n + 1] = N;
	for (int i = 1; i <= n; ++ i) input(ary[i]);

	for (int i = 2, u, v, w; i <= n; i += 2) {
		u = ary[i >> 1], v = ary[i], w = ary[i | 1];
		if (v < u and v < w) swap(ary[i >> 1], ary[i]);
		else if (w < v and w < u) {
			swap(ary[i >> 1], ary[i | 1]);
			if (u < v and get(u, i) < get(u, i | 1) or v < u and get(v, i) > get(v, i + 1))
				swap(ary[i], ary[i | 1]);
		}
	}
	for (int i = 1; i <= n; ++ i) output(ary[i], " \n"[i == n]);
	return 0;
}
