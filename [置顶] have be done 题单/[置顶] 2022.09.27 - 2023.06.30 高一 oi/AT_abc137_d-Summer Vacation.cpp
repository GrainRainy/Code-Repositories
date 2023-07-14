#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

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

const int N = 1e5 + 10;
int n, m;
struct Node{
	LL a, b;
}tasks[N];
LL sum;
priority_queue<int> heap;

inline bool cmp(const Node &a, const Node &b) {
	return a.a < b.a;
}

int main() {
	input(n), input(m);
	for (int i = 1; i <= n; i ++) {
		input(tasks[i].a);
		input(tasks[i].b);
	}
	
	sort(tasks + 1, tasks + 1 + n, cmp);
	
	int pos = 1;
	for (int i = 1; i <= m; i ++) {
		for (; tasks[pos].a <= i; pos ++) heap.push(tasks[pos].b);
		if (heap.size()) {
			sum += heap.top();
			heap.pop();
		}
	}
	cout << sum << endl;
	return 0;
}
