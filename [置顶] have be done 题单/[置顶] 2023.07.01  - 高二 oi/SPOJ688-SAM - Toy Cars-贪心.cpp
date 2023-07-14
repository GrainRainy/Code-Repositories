#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
 	}
}

using IO::input;
using namespace std;
const int N = 1e5 + 10;
const int P = 5e5 + 10;
int n, k, p, cnt, pos[N];
struct Toy {
	int type, nxt;
	bool operator < (const Toy &t) const {
		return nxt < t.nxt;
	}
}a[P];
bool ing[N];

void solve() {
	input(n), input(k), input(p);
	memset(ing, 0, sizeof(bool) * (n + 10));
	memset(pos, 0, sizeof(int) * (n + 10));
	cnt = 0;
	priority_queue<Toy> q;
	for (int i = 1; i <= p; ++ i) input(a[i].type);
	for (int i = p; i; -- i) {
		a[i].nxt = pos[a[i].type] ? pos[a[i].type] : p + 1;
		pos[a[i].type] = i;
	}
	for (int i = 1; i <= p; ++ i) {
		if (ing[a[i].type]) q.push(a[i]);
		else if (k) {
			ing[a[i].type] = true;
			q.push(a[i]);
			k --, cnt ++;
		} else {
			ing[q.top().type] = false;
			q.pop();
			ing[a[i].type] = true;
			q.push(a[i]);
			cnt ++;
		}
	}
	printf("%d\n", cnt);
	return;
}

int main() {
	int t; input(t);
	while (t --) solve();
	return 0;
}
