#include <iostream>

typedef long long LL;

using namespace std;

LL a, b, p;
LL ans = 1;

void fast_pow()
{
	LL pow = a;
	while (b > 0)
	{
		if (b & 1) ans = (ans % p * pow % p)  % p;
		pow = (pow % p * pow % p) % p;
		b = b >> 1;
	}
}

int main()
{
	cin >> a >> b >> p;
	LL tmp = b;
	fast_pow();
	cout << a << "^" << tmp << " mod " << p << "=" << ans << endl;
}
