#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

double ans, bag;

struct item
{
	double tw, tc;
	double cpw;
	
	bool operator < (const item &t) const
	{
		return cpw > t.cpw;
	}
}money[N];

int main()
{
	int n;
	cin >> n >> bag;
	for (int i = 0; i < n; i ++)
	{
		cin >> money[i].tw >> money[i].tc;
		money[i].cpw = money[i].tc / money[i].tw;
	}
	
	sort(money, money + n);
	
	for (int i = 0; i < n; i ++)
	{
		if (bag >= money[i].tw)
		{
			bag -= money[i].tw;
			ans += money[i].tc;
		}
		
		else
		{
			ans += bag * money[i].cpw;
			break;
		}
	}
	
	printf("%.2lf\n", ans);
	return 0;
		
}
