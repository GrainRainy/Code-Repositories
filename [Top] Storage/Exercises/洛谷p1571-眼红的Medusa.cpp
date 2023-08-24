#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int stu1[N], stu2[N];

int bsearch(int n, int x)
{
	int l = 0, r = n - 1, mid;
	
	while (l <= r)
	{
		mid = l + r >> 1;
		if (x == stu2[mid]) return mid;
		else if (x < stu2[mid]) r = mid - 1;
		else l = mid + 1; 
	}
	return -1;
}

int main()
{
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < a; i ++)
		cin >> stu1[i];
	for (int i = 0; i < b; i ++)
		cin >> stu2[i];
	
	sort(stu2, stu2 + b);
	
	for (int i = 0; i < a; i ++)
		if (bsearch(b, stu1[i]) != -1)
			cout << stu1[i] << " ";
	cout << endl;
	
	return 0;
 } #include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int stu1[N], stu2[N];

int bsearch(int n, int x)
{
	int l = 0, r = n - 1, mid;
	
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (x == stu2[mid]) return mid;
		else if (x < stu2[mid]) r = mid - 1;
		else l = mid + 1; 
	}
	return -1;
}

int main()
{
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < a; i ++)
		cin >> stu1[i];
	for (int i = 0; i < b; i ++)
		cin >> stu2[i];
	
	sort(stu2, stu2 + b);
	
	for (int i = 0; i < a; i ++)
		if (bsearch(b, stu1[i]) != -1)
			cout << stu1[i] << " ";
	cout << endl;
	
	return 0;
 } 
