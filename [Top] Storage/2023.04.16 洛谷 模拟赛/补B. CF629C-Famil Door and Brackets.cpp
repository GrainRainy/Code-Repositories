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

const int N = 1e5 + 10;
int n;
struct Cow{
	int time, milk;
	
	bool operator < (const Cow &t) const{
		return milk > t.milk;
	}
}nums[N];
bool flags;
LL ans = 0;
bool st[N];

int main(){
	input(n);
	for (int i = 1; i <= n; i ++){
		input(nums[i].milk), input(nums[i].time);
	}
	
	sort(nums + 1, nums + 1 + n);
	
	for (int i = 1; i <= n; i ++){
		for (int j = nums[i].time; j >= 1; j --){
			if (!st[j]){
				st[j] = true;
				ans += nums[i].milk;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
