#include <iostream>
#include <algorithm>
#define ULL unsigned long long 
using namespace std;

const int N = 1e5 + 10;
const int BASE = 131;

ULL n;
ULL hashi[N];

ULL gethash(string a)
{
	ULL ans;
	for (int i = 0; i < a.size(); i ++)
		ans = ans * BASE + a[i];
	return ans;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i ++)
	{
		string a;
		cin >> a;
		hashi[i] = gethash(a);
	}
	sort(hashi, hashi + n);
	
	int cnt = 0;
	for (int i = 1; i <= n; i ++)
		if (hashi[i]  != hashi[i - 1]) ++ cnt;
	cout << cnt << endl;
	return 0;
}
