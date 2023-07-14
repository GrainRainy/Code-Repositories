#include <iostream>

using namespace std;

typedef long long LL;

const int N = 35;

LL f[N][N], root[N][N];
int n, i;
bool firstwrite;

LL search(int l, int r)
{
	LL now, ans;
	if (l > r) return 1;
	if (f[l][r] == -1)
	{
		int k;
		for (k = l; k <= r; k ++)
		{
			now = search(l, k - 1) * search(k + 1, r) + f[k][k];
			if (now > f[l][r])
				f[l][r] = now, root[l][r] = k;
		}
	}
	return f[l][r];
}// search the subtree

void output(int l, int r)
{
	if (l > r) return;
	else if (firstwrite) firstwrite = false;
	else cout << ' ';
	
	cout << root[l][r];
	output(l, root[l][r] - 1), output(root[l][r] + 1, r);
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++)
		for (int j = i; j <= n; j ++)
			f[i][j] = -1;
			
	for (int i = 1; i <= n; i ++)
		cin >> f[i][i], root[i][i] = i;
	// input	
	
	cout << search(1, n) << endl;
	
	firstwrite = true;
	output(1, n);
	return 0;
}
