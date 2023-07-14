#include<bits/stdc++.h>

using namespace std;

int pg[505];
int m, k;
int lp[505], rp[505];

bool check(int x)
{
	int cnt = 1;
	int sum = 0;
	
	for(int i = 1; i <= m; i ++)
	{
		if(pg[i] > x)
		{
			cnt ++;
			continue;
		}
		if(sum + pg[i] <= x) sum += pg[i];
		else
		{
			cnt ++;
			sum = 0;
			sum += pg[i]; 
		}
		if(cnt > k) return 0;
	}
	return 1;
	
}
int main()
{
	long long sumx = 0;
	
	cin >> m >> k;
	for(int i = 1; i <= m; i ++)
	{
		cin >> pg[i];
		sumx += pg[i];
	}
	if(sumx == 0 || m == 0) return 0;
	long long mn = 0;
	long long l = 1, r = sumx;
	while (l <= r)
	{
		int mid = l + r >> 1;
		if(check(mid))
		{
			mn = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	int cntp = k, sum = 0;
	rp[cntp] = m;
	for(int i = m; i >= 1; i --)
		if(sum + pg[i] <= mn) sum += pg[i];
		else
			if(i == m)
			{
				lp[cntp] = m;
				cntp --;
				rp[cntp] = i - 1;
			}
			else
			{
				sum = pg[i];
				lp[cntp] = i + 1;
				cntp --;
				rp[cntp] = i;
			}
	lp[1] = 1;
	for(int i = 1; i <= k; i ++)
		cout << lp[i] << " " << rp[i] << endl;
	return 0;
}
