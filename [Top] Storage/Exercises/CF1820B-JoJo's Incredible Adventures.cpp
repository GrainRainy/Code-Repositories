#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
	

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
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top -- ] | '0');
	putchar(ed);
}

string a;
LL n;
LL cnt, tmp = 0;
LL ans = 0;
bool spe = 1;

void solve(){
	tmp = 0, ans = 0, cnt = 0, spe = 1;
	
	cin >> a;
	n = a.size();
	
	for (int i = 0; i < n; i ++){
		spe &= (a[i] == '1');
	}
	if (spe) return output((LL)n * n), void();
	// special judgement
	a = a + a;
	n = a.size();
	
	for (int i = 0; i <= n; i ++){
		if (a[i] == '1') tmp ++;
		else{
			cnt = max(cnt, tmp);
			tmp = 0;
		}
	}
	
	for (int i = 1; cnt - i + 1 >= 1; i ++){
		ans = max(ans, i * (cnt - i + 1));
	}
	output(ans);
}

int main(){
	int t; input(t);
	while (t --) solve();
	return 0;
}
