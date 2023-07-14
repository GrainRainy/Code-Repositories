#include <iostream>
#include <cstring>

#define fi first
#define se second

using namespace std;
using LL = long long;
using PII = pair<int, int>;

template <typename T> inline void input(T &x){
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

const int N = 3000 + 100;
int n;
PII a[N]; 

inline bool check(PII a, PII b, PII c){
	bool fo = ((a.fi - b.fi) == (b.fi - c.fi));
	bool fw = ((a.se - b.se) == (b.se - c.se));
	return (fo and fw);
}

int main(){
	ios::sync_with_stdio(false);
	cout.tie(0);
	
	input(n);
	for (int i = 1; i <= n; i ++){
		input(a[i].fi), input(a[i].se);
	}
	// input
	LL ans = n * (n - 1) * (n - 2) / 6;
	LL res = 0;
	for (int i = 1; i <= n; i ++){
		for (int j = 1; j <= n; j ++){
			if (i == j) continue;
			for (int k = 1; k <= n; k ++){
				if (k == i or k == j) continue;
				if (check(a[i], a[j], a[k])) res ++;
			}
		}
	}
	cout << ans - res / 2 << endl;
	return 0;
}
