#include <iostream>
#include <cstring>
#include <algorithm>
#define max(a, b) ((a > b) ? (a) : (b))

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

const int N = 1e5 + 100;
int n;
struct node{
	int cost, dist;
}nums[N];
bool st[N];

int main(){
	input(n);
	for (int i = 1; i <= n; i ++)
		input(nums[i].dist);
	for (int i = 1; i <= n; i ++){
		input(nums[i].cost);
	}
	// input
	
	int ans = 0, idx = 0;
	for (register int i = 1; i <= n; ++ i){
		int max_ans = 0, max_idx = 0;
		for (register int j = n; j > 0; -- j){
			if (st[j]) continue;
			if (idx >= j){
				if (max_ans < nums[j].cost){
					max_ans = nums[j].cost;
					max_idx = j;
				}
			}
			if (idx < j){
				if (max_ans < nums[j].cost + nums[j].dist * 2 - nums[idx].dist * 2){
					max_ans = nums[j].cost + nums[j].dist * 2 - nums[idx].dist * 2;
					max_idx = j;
				}
			}
		}
		st[max_idx] = true;
		ans += max_ans, idx = max(idx, max_idx);
		output(ans);
	}
	return 0;
}
