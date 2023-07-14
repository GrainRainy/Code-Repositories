#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e3 + 10;

struct people
{
	int tm, po;
}p[N];

bool cmp(people &a, people &b)
{
	if (a.tm != b.tm) return a.tm < b.tm;
	else return a.po < b.po;
}

int main()
{
	int n;
	cin >> n;
	int idx = 1;
	for (int i = 1; i <= n; i ++)
	{
		cin >> p[i].tm;
		p[i].po = idx;
		idx ++;
	}
	
	sort(p + 1, p + n + 1, cmp);
	
	long long sum = 0;
	for (int i = 1; i <= n; i ++)
	{
		cout << p[i].po << " ";
		sum += (n - i) * p[i].tm;
	}
	printf("\n%.2lf", sum * 1.0 / n);
	return 0;
}
