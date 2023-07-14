#include <iostream>
#include <cstring>
#include <algorithm>

#define owo 0                                                                                                                                                                                        

using namespace std;
using LL = long long;

template <typename T> inline void input(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x* 10 + (c ^ '0');
	if (f) x = -x;
}

int n;
LL maxn = -1, ans = -1;
int PrimeList[20] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

void dfs(LL u, int idx, int cnt, int pr) {
	if (cnt > maxn or cnt == maxn and u < ans) {
		ans = u, maxn = cnt;
	}
	
	int ncnt, i = 0; LL tmp = u;
	while (i < pr) {
		i ++;
		if (n / tmp < PrimeList[idx]) break;
		ncnt = cnt * (i + 1);
		tmp = tmp * PrimeList[idx];
		if (tmp <= n) dfs(tmp, idx + 1, ncnt, i);
	}
	return;
}

int main(){
	input(n);
	dfs(1, 1, 1, 30);
	return cout << ans << '\n', owo;
}
