#include <iostream>

template <typename T> inline void input(T &x){
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}
using namespace std;

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}

int x, y;

int main(){
	int n; input(n);
	while (n --) input(x), input(y), printf("%d\n", gcd(x, y));
	return 0;
}
