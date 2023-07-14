#include <iostream>
#include <cstring>
#include <algorithm>

#define fi first
#define se second

using namespace std;
using LL = long long;
using PII = pair<int, int>;

template<typename T> inline void input(T &x){
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

const int N = 3000 + 10;
const int INF = 1e8;
int n;
PII a[N];
LL ans;
double gdt[N];
int idx;

double gradient(PII x, PII y){
	return (x.se - y.se) / (double)(x.fi - y.fi);
}

int main(){
	input(n);
	for (int i = 1; i <= n; i ++){
		input(a[i].fi), input(a[i].se);
	}
	ans = (LL)n * (n - 1) * (n - 2) / 6;
	// input and init ans
	
	for (int i = 1; i <= n - 2; i ++){
		idx = 0;
		for (int j = i + 1; j <= n; j ++){
			if (a[i].fi - a[j].fi == 0) gdt[++ idx] = INF;
			else gdt[++ idx] = gradient(a[i], a[j]);
		}
		// init gradient
		sort(gdt + 1, gdt + idx + 1);
		int cnt = 1;
		for (int j = 2; j <= idx; j ++){
			if (gdt[j - 1] == gdt[j]) cnt ++;
			else ans -= (LL)cnt * (cnt - 1) / 2, cnt = 1;
		}
		ans -= (LL)cnt * (cnt - 1) / 2;
	}
	cout << ans << endl;
}
