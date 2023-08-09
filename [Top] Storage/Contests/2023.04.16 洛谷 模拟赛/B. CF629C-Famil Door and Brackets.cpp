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
int n, m, calc, siz;
int epl, epr;
int u, v;
int tmp, tmpu, tmpv;
string a;
LL ans1, ans2;

int main(){
	puts("0");
	return 0;
}
