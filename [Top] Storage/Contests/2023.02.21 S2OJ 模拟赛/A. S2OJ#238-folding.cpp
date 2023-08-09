#include <bits/stdc++.h>
#include <cstring>
using namespace std;

const int N = 110;
int n;
int ans = 0;
string s;

int get_wei(int x)
{
	int tmp = 0;
	while (x) tmp ++, x /= 10;
	return tmp;
}

int main()
{
//	freopen("folding.in", "r", stdin);
//	freopen("folding.out", "w", stdout);
	
	cin >> s;
	n = s.size();
	if (n <= 4)
	{
		cout << n << endl;
		return 0;
	}
	// protest 1
	
	bool flag;
	do
	{
		flag = false;
		for (int i = 0; i < n; i ++)
		for (int len = 1; i + len <= n; len ++)
		{
			int cnt = 1;
			int maxr = i + len; // ²»°üº¬ 
			while(s.substr(i, len) == s.substr(maxr, len) and maxr + len - 1 <= n)
				maxr = maxr + len, cnt ++;
			if (maxr - i > get_wei(cnt) + 2 + len)
			{
				flag = true;
				
				char c = (cnt | '0');
				s = s.substr(0, i) + c + '(' + s.substr(i, len) + ")" + s.substr(maxr);
				n = s.size();
			}
		}
	} while (flag);
	
	cerr << s << endl;
	cout << s.size() << endl;
	return 0;
}
