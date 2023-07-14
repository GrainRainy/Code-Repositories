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

int n;
string a;
bool l = false, r = false;
int ans;

void solve(){
	ans = 0;
	l = false, r = false;
	cin >> a;
	n = a.size();
	if (n == 1 and a[0] == '^') return output(1), void();
	
	for (int i = 0; i < n; i ++){
		if (a[i] == '_'){
			r |= (a[i + 1] == '^');
			if (!l) ans ++;
			if (!r) ans ++;
			l = true, r = false;
		}
		else l = true;
	}
	output(ans);
	return;
}

int main(){
	int t; input(t);
	while (t --) solve();
	return 0;
}
