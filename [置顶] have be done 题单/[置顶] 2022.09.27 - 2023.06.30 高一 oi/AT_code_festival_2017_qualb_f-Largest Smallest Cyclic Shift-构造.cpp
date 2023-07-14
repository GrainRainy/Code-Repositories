#include <iostream>
#include <cstring>
#include <set>

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
int a, b, c, cnt;
multiset<string> stk;

int main() {
	input(a), input(b), input(c);
	cnt = a + b + c;
	while (a --) stk.insert("a");
	while (b --) stk.insert("b");
	while (c --) stk.insert("c");
	while (stk.size() > 1) {
		auto tmpa = stk.begin(), tmpb = -- stk.end();
		stk.insert(*tmpa + *tmpb);
		stk.erase(tmpa), stk.erase(tmpb);
	}
	cout << *stk.begin() << '\n';
	return 0;
}
