#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

int n, m;
LL ans;

LL C3(LL a){
	return (a * (a - 1) * (a - 2) / 6);
}

int main(){
	cin >> n >> m;
	ans = C3((n + 1) * (m + 1));
	// sum 
	
	ans -= (m + 1) * C3(n + 1);
	ans -= (n + 1) * C3(m + 1);
	// in one line 
	
	LL cnt = 0;
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= m; ++ j){
			cnt += (n - i + 1) * (m - j + 1) * (__gcd(i, j) - 1);
		}
	}
	// others 
	cout << ans - 2 * cnt << endl;
	return 0;
}
