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
LL n, m;
struct Node{
	LL x, t;
	
	bool operator < (const Node &t) const {
		return x < t.x;
	}
}nums[N];
priority_queue<LL> heap;
LL tim, cnt, ans;

int main() {
	input(n), input(m);
	for (int i = 1; i <= n; i ++) {
		input(nums[i].x), input(nums[i].t);
	}
	sort(nums + 1, nums + 1 + n);
	
	for (int i = 1; i <= n; i ++) {
		tim += nums[i].x - nums[i - 1].x;
		tim += nums[i].t;
		heap.push(nums[i].t);
		cnt ++;
		while (heap.size() and tim > m) {
			tim -= heap.top();
			heap.pop();
			cnt --;
		}
		if (tim > m) break;
		ans = max(cnt, ans);
	}
	cout << ans << endl;
	return 0;
}
