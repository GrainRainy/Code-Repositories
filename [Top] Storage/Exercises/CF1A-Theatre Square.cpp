#include <iostream>
#include <cmath>

using namespace std;

typedef long long LL;

int main()
{
	int n, m, a;
	cin >> n >> m >> a;
	cout << (LL)ceil(n * 1.0 / a) * (LL)ceil(m * 1.0 / a) << endl;
	return 0;
}
