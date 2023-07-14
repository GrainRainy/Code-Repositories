#include <iostream>
#include <cstring>
#include <queue>
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

const int N = 1e4 + 10;
int n;
struct Cow{
	int d, g;
	
	bool operator < (const Cow &t) const{
		return g > t.g;
	}
}nums[N];
bool st[N];
int cnt = 1, ans;
int maxn;

bool cmp(const Cow &a, const Cow &b){
	if (a.d != b.d) return a.d < b.d;
	else return a.g > b.g;
}

priority_queue<Cow> heap;

int main(){
	input(n);
	for (int i = 1; i <= n; i ++){
		input(nums[i].g), input(nums[i].d);
		maxn = max(nums[i].d, maxn);
	}
	// input
	sort(nums + 1, nums + n + 1, cmp);
	for (int i = 1; i <= n; i ++){
		if (cnt <= nums[i].d) ans += nums[i].g, st[i] = true, cnt ++;
		if (cnt > maxn){
			for (int j = i; j <= n; j ++){
				heap.push(nums[j]);
			}
		}
	}
	
	int idx = 1;
	while (!st[idx] and idx <= n) idx ++;
	while (heap.size() and heap.top().g > nums[idx].g and heap.top().d >= nums[idx].d){
		ans = ans - nums[idx].g + heap.top().g;
		heap.pop();
		while (!st[idx] and idx <= n) idx ++;
	}
	
	cout << ans << endl;
}
