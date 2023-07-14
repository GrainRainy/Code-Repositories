#include <iostream>
#include <algorithm>
using namespace std;

struct pai
{
	int x;
	double y;
	string z;
	
	bool operator < (const pai &t) const
	{
		return x < t.x;
	}
}a[10010];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> a[i].x >> a[i].y >> a[i].z;
	
	sort(a, a + n);
	
	for (int i = 0; i < n; i ++)
	{
		printf("%d %.2lf ", a[i].x, a[i].y);
		cout << a[i].z << endl;
	}
//		cout << a[i].x << " " << a[i].y << " " << a[i].z << endl;
		
	return 0;
	
}
