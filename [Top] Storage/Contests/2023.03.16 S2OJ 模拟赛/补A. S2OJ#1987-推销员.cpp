#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

template <typename T> inline void input(T &x){
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

template <typename T> inline void output(T x, char ed = '\n'){
	if (x < 0) putchar('-'), x = -x;
	static short st[64], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

const int N = 1e5 + 10;
int n;
struct node{
	int dist, cost;
	
	bool operator > (const node &t) const{
		return cost > t.cost;
	}
}nums[N];

int cost_sum[N], front[N], back[N];

int main(){
	input(n);
	for (int i = 1; i <= n; i ++) input(nums[i].dist);
	for (int i = 1; i <= n; i ++) input(nums[i].cost);
	// input
	sort(nums + 1, nums + 1 + n, greater<node>());
	for (int i = 1; i <= n; i ++)
		cost_sum[i] = cost_sum[i - 1] + nums[i].cost;
	for (int i = 1; i <= n; i ++)
		front[i] = max(front[i - 1], 2 * nums[i].dist);
	for (int i = n; i > 0; i --)
		back[i] = max(back[i + 1], 2 * nums[i].dist + nums[i].cost);
	for (int i = 1; i <= n; i ++)
		output(max(cost_sum[i] + front[i], cost_sum[i - 1] + back[i]));
	return 0;
}
