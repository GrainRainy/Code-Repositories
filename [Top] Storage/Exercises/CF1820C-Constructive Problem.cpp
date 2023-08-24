#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;
using LL = long long;

template <typename T> inline void input(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

const int N = 2e5 + 10;
int n;
int nums[N];
int minl = 1e8, maxr = 0;

int calc() {
	map<int, int> st;
	for (int i = 1; i <= n; i ++) {
		st[nums[i]] ++;
	}
	for (int i = 0; ; i ++) {
		if (st.find(i) == st.end()) return i;
	}
}

void solve() {
	minl = 1e8, maxr = 0;
	
	input(n);
	for (int i = 1; i <= n; i ++) input(nums[i]);
	// input
	
	int tmp = calc();
	
	for (int i = 1; i <= n; i ++) {
		if (nums[i] == tmp + 1){
			minl = min(minl, i);
			maxr = max(maxr, i);
		}
	}
	if (minl == 1e8) {
		if (tmp == n) return puts("no"), void();
		return puts("yes"), void();
	}
	for (int i = minl; i <= maxr; i ++) {
		nums[i] = tmp;
	}
	int nw = calc();
	if (nw == tmp + 1) return puts("yes"), void();
	return puts("no"), void();
}

int main() {
	int t; input(t);
	while (t --) solve();
	return 0;
}
