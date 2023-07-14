#include <iostream>
#include <cstring>
#include <algorithm>

#define owo 0

using namespace std;

template <typename T> inline void input(T &x){
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x* 10 + (c ^ '0');
	if (f) x = -x;
}

const int N = 1e6 + 10;
int n;
int primes[N], top;
bool notPrime[N];

void init(){
	notPrime[0] = notPrime[1] = true;
	for (int i = 2; i <= n; i ++){
		if (!notPrime[i]) primes[++ top] = i;
		for (int j = 1; primes[j] <= n / i; j ++){
			notPrime[primes[j] * i] = true;
			if (i % primes[j] == 0) break;
		}
	}
}

int main(){
	input(n);
	init();
	cout << top << endl;
	return owo;
}
