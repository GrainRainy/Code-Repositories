#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2010;

int hs1[N], hs2[N];
int n, mny;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> hs1[i];
	for (int i = 1; i <= n; i ++)
		cin >> hs2[i];
	
	sort (hs1 + 1, hs1 + n + 1, greater<int>());
	sort (hs2 + 1, hs2 + n + 1, greater<int>());
	// input
	
	for (int i = 1; i <= n; i ++)
		cerr << hs1[i] << " ";
	cerr << endl;
	for (int i = 1; i <= n; i ++)
		cerr << hs2[i] << " ";
	cerr << endl;
	
	int l1 = 1, r1 = n, l2 = 1, r2 = n;
	// 1 refers to TianJi, 2 refers to the King
	
	while (l1 <= r1 && l2 <= r2)
		if (hs1[l1] > hs2[l2]) l1 ++, l2 ++, mny ++;
		else if (hs1[l1] < hs2[l2]) r1 --, l2 ++, mny --;
		else 
			if (hs1[r1] > hs2[r2]) r1 --, r2 --, mny ++;
			else 
			{
				if (hs1[r1] < hs2[l2]) mny --;
				r1 --, l2 ++;
			}
			
	cout << mny * 200 << endl;
	
	return 0;
	
}
