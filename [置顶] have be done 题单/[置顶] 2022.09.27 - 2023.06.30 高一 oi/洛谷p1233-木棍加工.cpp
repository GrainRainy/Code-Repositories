#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5010;

struct stick
{
	int len, wid;
}stk[N];

bool cmp(stick &a, stick &b)
{
	if (a.len != b.len) return a.len > b.len;
	else return a.wid > b.wid;
}

int q[N];

int main()
{	
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> stk[i].len >> stk[i].wid;
	
	sort(stk, stk + n, cmp);
	
	int lenth = 0;
	q[0] = -1;
	
	for (int i = 0; i < n; i ++)
	{
		int l = 0, r = lenth;
		while (l < r)
		{
			int mid = l + r + 1 >> 1;
			if (q[mid] < stk[i].wid) l = mid;
			else r = mid - 1;
		}
		lenth = max(lenth, r + 1);
		q[r + 1] = stk[i].wid;
	}
	
	cout << lenth << endl;
	
	return 0;
}
