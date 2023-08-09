#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>

#define reduce 0.96

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
int nums[N];

int sum = 0, tmpsum;
double ans = 0x3f3f3f3f, tmpans;

void calc(int l, int r){
	tmpsum = sum;
	for (int i = l; i <= r; i ++){
		tmpsum -= nums[i];
	}
	tmpans = tmpsum * 1.0 / (n - (r - l + 1));
	ans = min(tmpans, ans);
	return;
}

int main(){
	input(n);
	for (int i = 1; i <= n; i ++){
		input(nums[i]);
		sum += nums[i];
	}
	// input
	for (int l = 2; l < n; l ++){
		for (int r = l; r < n; r ++){
			calc(l, r);
		}
	}
	printf("%.3lf", ans);
	return 0;
}
