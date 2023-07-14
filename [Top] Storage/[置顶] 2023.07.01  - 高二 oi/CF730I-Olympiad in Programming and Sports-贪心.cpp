#include <bits/stdc++.h>
#define fi first
#define se second
#define debug(x) cerr << #x << ' ' << x << endl; 
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
		static short st[40], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}  
}

using namespace IO;
using namespace std;
using PII = pair<int, int>;
const int N = 3e3 + 10;
const int INF = 0x3f3f3f3f;
int n, p, s, sum;
struct Psn {
	int a, b, id;
	bool operator > (const Psn &t) const { return a > t.a; } 
}per[N];
int st[N];
priority_queue<PII> a, b, b_a;

bool cmp(Psn a, Psn b) { return a.id < b.id; }

int main() {
	input(n), input(p), input(s);
	for (int i = 1; i <= n; ++ i) input(per[i].a);
	for (int i = 1; i <= n; ++ i) {
		input(per[i].b); per[i].id = i;
		a.push({per[i].a, i});
		b.push({per[i].b, i});
		b_a.push({per[i].b - per[i].a, i});
	}
	sort(per + 1, per + n + 1, greater<Psn>());
	for (int i = 1; i <= p; ++ i) sum += per[i].a, st[per[i].id] = 1;
	sort(per + 1, per + n + 1, cmp);
	for (int i = 1; i <= s; ++ i) {
		int val = -INF, posa = 0, posb = 0, opt = 0;
		while (a.size() and st[a.top().se]) a.pop();
		while (b.size() and st[b.top().se]) b.pop();
		while (b_a.size() and st[b_a.top().se] != 1) b_a.pop();
		if (b.size() and b.top().fi > val) {
			val = b.top().fi;
			posa = b.top().se;
			opt = 1;
		}
		if (a.size() and b_a.size() and a.top().fi + b_a.top().fi > val) {
			val = a.top().fi + b_a.top().fi;
			posb = a.top().se, posa = b_a.top().se;
			opt = 2;
		}
		sum += val;
		if (opt == 1) b.pop(), st[posa] = 2;
		else {
			a.pop(), b_a.pop();
			st[posa] = 2, st[posb] = 1;
			b_a.push({per[posb].b - per[posb].a, posb});
		}
	}
	output(sum);
	for (int i = 1; i <= n; ++ i) if (st[i] == 1) output(i, ' ');
	puts("");
	for (int i = 1; i <= n; ++ i) if (st[i] == 2) output(i, ' ');
	puts("");
	return 0;
}
