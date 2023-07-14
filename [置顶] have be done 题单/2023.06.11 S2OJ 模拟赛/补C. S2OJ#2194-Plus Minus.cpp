#include <iostream>
#include <cstring>
#include <algorithm>

namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x  *10 + (c ^ '0');
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
using LL = long long;

const int K = 1e5 + 10;
const int MOD = 1e9 + 7;
int n, m, k, ans;
struct DATA {
	int x, y; bool type;
}ary[K];

bool cmpX(DATA &a, DATA &b) { 
	return (a.x ^ b.x) ? a.x < b.x : a.y < b.y;
}

bool cmpY(DATA &a, DATA &b) {
	return (a.y ^ b.y) ? a.y < b.y : a.x < b.x;
}

int get() {
	char c;
	do c = getchar(); while (c != '+' and c != '-');
	return (c == '+') ? 1 : 0;
}

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (LL)res * a % MOD;
		a = (LL)a * a % MOD;
		b >>= 1;
	}
	return res;
}

int calculateX() {
	sort(ary + 1, ary + 1 + k, cmpX);
	int res = 0, pre = 0;
	bool judgea = false, judgeb = false;
	for (int l = 1, r = 0; l <= k; l = r + 1) {
		while (r < k and ary[r + 1].x == ary[l].x) r ++;
		for (int i = l; i <= r; ++ i) {
			judgea = (ary[i].y ^ ary[l].y) & 1;
			judgeb = ary[i].type ^ ary[l].type;
			if (judgea ^ judgeb) return 0;
		}
		res += ary[l].x - pre - 1;
		pre = ary[l].x;
	}
	res += n - pre;
	return qpow(2, res);
}

int calculateY() {
	sort(ary + 1, ary + 1 + k, cmpY);
	int res = 0, pre = 0;
	bool judgea = false, judgeb = false;
	for (int l = 1, r = 0; l <= k; l = r + 1) {
		while (r < k and ary[r + 1].y == ary[l].y) r ++;
		for (int i = l; i <= r; ++ i) {
			judgea = (ary[i].x ^ ary[l].x) & 1;
			judgeb = ary[i].type ^ ary[l].type;
			if (judgea ^ judgeb) return 0;
		}
		res += ary[l].y - pre - 1;
		pre = ary[l].y;
	}	
	res += m - pre;
	return qpow(2, res);
}

int calculateXY() {
	bool judgea = false, judgeb = false;
	for (int i = 1; i <= k; ++ i) {
		judgea = (ary[1].x ^ ary[1].y ^ ary[i].x ^ ary[i].y) & 1;
		judgeb = (ary[1].type ^ ary[i].type);
		if (judgea ^ judgeb) return 0;
	}
	return 1;
}

int main() {
	input(n), input(m), input(k);
	for (int i = 1; i <= k; ++ i) {
		ary[i].type = get();
		input(ary[i].x), input(ary[i].y);
	}
	ans = ((LL)ans + calculateX()) % MOD;
	ans = ((LL)ans + calculateY()) % MOD;
	ans = ((LL)ans - calculateXY() + MOD) % MOD;
	if (!k) ans = ((LL)ans - 1 + MOD) % MOD;
	output(ans);
}
