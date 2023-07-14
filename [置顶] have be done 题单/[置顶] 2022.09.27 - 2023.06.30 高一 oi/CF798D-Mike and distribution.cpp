#include <iostream>
#include <cstring>
#include <algorithm>

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

template <typename T> inline void output(T x, char ed = ' ') {
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

const int N = 1e5 + 10;
int n;
struct Node{
	int a, b, idx;
}nums[N];

bool cmp(const Node &a, const Node &b) {
	return a.a > b.a;
}

int maxn(const Node &a, const Node &b) {
	if (a.b > b.b) return a.idx;
	return b.idx;
}

int main() {
	input(n);
	for (int i = 1; i <= n; ++ i) input(nums[i].a);
	for (int i = 1; i <= n; ++ i) input(nums[i].b), nums[i].idx = i;
	sort(nums + 1, nums + n + 1, cmp);
	
//	for (int i = 1; i <= n; i ++) {
//		cout << nums[i].a << " " << nums[i].b << " " << nums[i].idx << endl;
//	}
	
	output(n / 2 + 1, '\n'), output(nums[1].idx);
	for (int i = 2; i <= n; i += 2) output(maxn(nums[i], nums[i + 1]));
	return 0;
}
