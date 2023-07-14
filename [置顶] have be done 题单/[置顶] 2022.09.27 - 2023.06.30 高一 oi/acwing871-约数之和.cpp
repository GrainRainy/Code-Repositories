#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;
using LL = long long;

template <typename T> inline void input(T &x){
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10+ (c ^ '0');
	if (f) x = -x;
}

const int MOD = 1e9 + 7;
unordered_map<int, int> primes;
LL res = 1;

void add(int u){
	for (int i = 2; i <= u / i; i ++){
		while (u % i == 0){
			u /= i;
			primes[i] ++;
		}
	}
	if (u > 1) primes[u] ++;
}

int main(){
	int n, tmp; input(n);
	while (n --) input(tmp), add(tmp);
	for (auto pos : primes){
		LL a = pos.first, b = pos.second;
		LL tmp = 1;
		while (b --) tmp = (tmp * a  + 1) % MOD;
		res = res * tmp % MOD;
	}
	cout << res << endl;
	return 0;
}
