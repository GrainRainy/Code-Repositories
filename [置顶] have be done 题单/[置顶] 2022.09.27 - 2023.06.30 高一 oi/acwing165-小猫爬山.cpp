#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 20;
int n, m;
int nums[N], cars[N];
int ans = N;

void dfs(int cat, int cnt)
{
	if (cnt >= ans) return;
	if (cat == n + 1)
	{
		ans = cnt;
		return;
	}
	
	for (int i = 0; i < cnt; ++ i)
		if (cars[i] + nums[cat] <= m)
		{
			cars[i] += nums[cat];
			dfs(cat + 1, cnt);
			cars[i] -= nums[cat];
		}
	
	cars[cnt] = nums[cat];
	dfs(cat + 1, cnt + 1);
	cars[cnt] = 0;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n ; i++)
		cin >> nums[i];
	// input
	
	dfs(1, 1);
	
	cout << ans << endl;
	return 0;
}
