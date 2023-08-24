#include <iostream>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;
using LL = long long;
using PLLL = pair<pair<LL, LL>, LL>;

template <typename T> inline void input (T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x; 
}

template <typename T> inline void output(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[16], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

int x, y, z, k, i;
LL ary[1010], bry[1010], cry[1010];
struct Node {
	LL a, b, c; 
	bool operator < (const Node &t) const {
		return ary[a] + bry[b] + cry[c] < ary[t.a] + bry[t.b] + cry[t.c];
	}
};

priority_queue<Node> heap; // store the position of val 
map<PLLL, bool> st;

int main() {
	input(x), input(y), input(z), input(k);
	for (i = 1; i <= x; ++ i) input(ary[i]);
	for (i = 1; i <= y; ++ i) input(bry[i]);
	for (i = 1; i <= z; ++ i) input(cry[i]);
	
	sort(ary + 1, ary + 1 + x, greater<LL>());
	sort(bry + 1, bry + 1 + y, greater<LL>());
	sort(cry + 1, cry + 1 + z, greater<LL>());
	
	heap.push({1, 1, 1});
	st[{{1, 1}, 1}] = true;
	while (k --) {
		Node u = heap.top(); heap.pop();
		output(ary[u.a] + bry[u.b] + cry[u.c]);

		if (u.a < x and st.find({{u.a + 1, u.b}, u.c}) == st.end())	
			heap.push((Node){u.a + 1, u.b, u.c}), st[{{u.a + 1, u.b}, u.c}] = true;
		if (u.b < y and st.find({{u.a, u.b + 1}, u.c}) == st.end())	
			heap.push((Node){u.a, u.b + 1, u.c}), st[{{u.a, u.b + 1}, u.c}] = true;
		if (u.c < z and st.find({{u.a, u.b}, u.c + 1}) == st.end())	
			heap.push((Node){u.a, u.b, u.c + 1}), st[{{u.a, u.b}, u.c + 1}] = true;
	}
	return 0;
}
