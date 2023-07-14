#include <bits/stdc++.h>

#define enter putchar('\n')
#define FI first
#define SE second

namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar(); bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
	template <typename T, typename... Args> 
	void input(T &x, Args&... args) {
		input(x), input(args...);
	}
	template <typename T> inline void output(T x, char ed = '\n') {
		if (x < 0) putchar('-'), x = -x;
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
}

using namespace std;
using namespace IO;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;

const int N = 300;
int n, mv = 0x3f3f3f3f, mp;
struct person{
	string name; int age;
}per[N];

int main() {
	input(n);
	for (int i = 1; i <= n; ++ i) {
		cin >> per[i].name;
		input(per[i].age);
		per[i + n].name = per[i].name;
		per[i + n].age = per[i].age;
		if (mv > per[i].age) mv = per[i].age, mp = i;
	}
	for (int i = mp; i < mp + n; ++ i) {
		cout << per[i].name << '\n';
		
	}]
	return 0;
}
