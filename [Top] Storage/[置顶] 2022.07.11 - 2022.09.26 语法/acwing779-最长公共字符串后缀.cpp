#include <bits/stdc++.h>
using namespace std;

string a[200];

int main()
{
	int n;
	while (cin >> n, n)
	{
		string ans = {};
		bool is_same = 1; 
	    int len = 1000;
		for (int i = 0; i < n; i ++)
		{
			cin >> a[i];
			if (len > a[i].size())
			    len = a[i].size();
	    }
		for (int i = 1; i <= len; i ++)//��ͬλ�� 
		{
			int j = 1;
			for (; j < n; j ++)//n���ַ��� 
			{
				
				if (a[j][a[j].size() - i] != a[0][a[0].size() - i])
					is_same = 0;
			}
			if (is_same) ans = a[0][a[0].size() - i] + ans;
		}
		cout << ans << endl;
	}
	return 0;
}

