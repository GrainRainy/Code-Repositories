#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

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

int a[4];

inline bool check(int a, int b, int c, int d){
	return ((a < b) and (d < c) and (a < d) and (b < c));
}

inline void solve(){
	input(a[0]), input(a[1]), input(a[3]), input(a[2]);
	bool f = false;
	f |= check(a[0], a[1], a[2], a[3]);
	f |= check(a[3], a[0], a[1], a[2]);
	f |= check(a[2], a[3], a[0], a[1]);
	f |= check(a[1], a[2], a[3], a[0]);
	if (f) cout << "yes" << endl;
	else cout << "no" << endl;
}

int main(){
	int t; input(t);
	while (t --) solve();
	return 0;
}
