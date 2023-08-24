#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;
using LL = long long;

LL n, k;
LL cntqr, cntcm;
map<LL, bool> st;

int main(){
	cin >> n >> k;
	if (k == 1) return cout << n << endl, 0;
	for (LL i = 2; i * i * i <= n; i ++){
		LL tmp = i * i, m = 2;
		while (tmp < n / i){
			tmp *= i, ++ m;
			if (m < k or st[tmp]) continue;
			if ((LL)sqrtl(tmp) * (LL)sqrtl(tmp) == tmp) cntqr ++;
			st[tmp] = true, cntcm ++;
		}
	}
	if (k == 2) return cout << (LL)sqrtl(n) + cntcm - cntqr << endl, 0;
	else cout << cntcm + 1 << endl; return 0;
}
