#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

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

LL a, b, x, y;

LL exgcd(LL a, LL b, LL &x, LL &y){
	if (!b){
		x = 1, y = 0;
		return a;
	}
	LL d = exgcd(b, a % b, x, y);
	LL tmp = x;
	x = y;
	y = tmp - (a / b) * y;
	return d;
}

int main(){
	input(a), input(b);
	LL d = exgcd(a, b, x, y);
	while (x < 0) x += b / d;
	cout << x / d << endl;
	return 0;
}
