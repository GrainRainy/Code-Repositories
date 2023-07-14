#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

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

const int N = 1.5e5 + 10;

int n, cnt;
LL now;
struct Buildings{
	LL a, b;
	
	bool operator < (const Buildings &t) const{
		return b < t.b;
	}
}nums[N];
priority_queue<int> heap;

int main(){
	input(n);
	for (int i = 1; i <= n; ++ i){
		input(nums[i].a), input(nums[i].b);
	}
	// input 
	sort(nums + 1, nums + n + 1);
	
	for (int i = 1; i <= n; ++ i){
		if (now + nums[i].a < nums[i].b){
			now += nums[i].a, cnt ++;
			heap.push(nums[i].a);
		}
		else if (nums[i].a < heap.top()){
			now = now - heap.top() + nums[i].a;
			heap.pop();
			heap.push(nums[i].a);
		}
	}
	cout << cnt << endl;
	return 0;
}
