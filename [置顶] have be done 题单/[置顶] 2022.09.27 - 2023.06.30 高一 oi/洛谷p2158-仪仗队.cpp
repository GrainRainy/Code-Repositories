#include <iostream>
#include <cstring>
#include <algorithm>

#define owo 0

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

const int N = 4e4 + 10;
int n;
LL ans;
int phi[N];

void Euler(int n) {
	for (int i = 2; i <= n; ++ i) phi[i] = i;
	for (int i = 2; i <= n; ++ i) {
		if (phi[i] == i) {
			for (int j = i; j <= n; j += i) {
				phi[j] = phi[j] / i * (i - 1);
			}
		}
	}
}

int main() {
	input(n);
	if (n == 1) return puts("0"), owo;
	
	Euler(n);
	for (int i = 2; i < n; ++ i) {
		ans += phi[i];
	}
	
	return cout << (ans << 1) + 3 << '\n', owo;
}
