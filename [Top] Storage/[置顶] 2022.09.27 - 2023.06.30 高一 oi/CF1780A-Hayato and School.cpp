#include <iostream>

using namespace std;

const int N = 310;

int t;
int idxa, idxb;
int odd[N], nodd[N];
// idx and value

void solve()
{
	idxa = 0, idxb = 0;
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++)
	{
		int tmp;
		cin >> tmp;
		if (tmp % 2) odd[++ idxb] = i;
		else nodd[++ idxa] = i;
	}
	
	if (idxb >= 3)
	{
		cout << "YES" << endl;
		cout << odd[1] << " " << odd[2] << " " << odd[3] << endl;
	}
	else if (idxa >= 2 && idxb)
	{
		cout << "YES" << endl;
		cout << odd[1] << " " << nodd[1] << " " << nodd[2] << endl;
	}
	else cout << "NO" << endl;
	return;
}

int main()
{
	cin >> t;
	while (t --) solve();
	return 0;
}
