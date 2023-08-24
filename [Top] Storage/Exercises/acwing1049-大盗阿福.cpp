#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;
int n;
int nums[N];
int f[N][2];
// chosed or not 

void solve()
{
	int n;
	cin >> n;
	f[0][0] = 0, f[0][1] = -INF;
	for (int i = 1; i <= n; i ++)
		cin >> nums[i];
	// input
	for (int i = 1; i <= n; i ++)
	{
		f[i][0] = max(f[i - 1][1], f[i - 1][0]);
		f[i][1] = f[i - 1][0] + nums[i];
	}
	cout << max(f[n][0], f[n][1]) << endl;
	memset(f, 0, sizeof f);
	return;
}

int main()
{
	int t;
	cin >> t;
	while (t --) solve();
	return 0;
}
