#include <iostream>
#include <algorithm>

using namespace std;

int times;

int len(int u)
{
	int cnt = 0;
	while (u)
	{
		cnt ++;
		u >>= 1;
	}
	return cnt;
}

int main()
{
	scanf("%d", &times);
	while (times --)
	{
		int n;
		scanf("%d", &n);
		if (n % 2 == 0) printf("-1\n");
		else printf("%d\n", len(n));
	}
	return 0;
}
