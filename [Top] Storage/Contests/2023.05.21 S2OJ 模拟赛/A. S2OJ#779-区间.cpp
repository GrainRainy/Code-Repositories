#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 2e7 + 10;
LL n, k, p;
LL a, b, c, d;
LL s[N], tmul, ans = 0;
LL inv, y;
bool flags;

LL exgcd(LL a, LL b, LL &x, LL &y){
	if (!b) { x = 1, y = 0; return a; }
	LL gcd = exgcd(b, a % b, x, y);
	LL tmp = x;
	x = y, y = tmp - (a / b) * y;
	return gcd;
}

int main() {
    scanf("%d%d%d", &n, &k, &p);
    scanf("%d%d%d%d", &a, &b, &c, &d);
    
	for (int i = 2; i <= p / i; ++ i) {
		if (p % i == 0) { flags = true; break; }
	}
	
	if (n <= 5e4 and flags) {
		s[1] = a;
		for (int i = 2; i <= n; ++ i) {
			s[i] = (s[i - 1] * b + c) % d;	
		}
		for (int i = 1; i <= n - k + 1; ++ i) {
			tmul = 1;
			for (int j = i; j <= i + k - 1; ++ j) {
				tmul = tmul * s[j] % p;
			}
			ans ^= tmul;
		}
		printf("%d\n", ans);
		return 0;
	}

    s[1] = a, tmul = s[1];
    for (int i = 2; i <= n; ++ i) { // right 
        s[i] = (s[i - 1] * b + c) % d;
        if (i < k) { tmul = tmul * s[i] % p; continue; }
		if (i == k) {
			tmul = tmul * s[i] % p;
			ans = tmul;
			continue;
		}
        inv = 0, y = 0;
        exgcd(s[i - k], p, inv, y); // nlog 
        inv = (inv % p + p) % p;
        tmul = inv * tmul % p * s[i] % p;
        // calculate now tmul 
        ans ^= tmul;
    }

    printf("%d\n", ans);
	
    return 0;
}
