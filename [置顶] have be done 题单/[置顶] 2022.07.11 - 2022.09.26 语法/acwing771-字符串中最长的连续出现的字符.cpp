	#include <bits/stdc++.h>
	using namespace std;
	
	int main()
	{
		int n;
		cin >> n;
		while (n --)
		{
			string a;
			cin >> a;
			int mc, mcnt = 0;
			for (int i = 0; i < a.size(); i ++)
			{
				int j = i;
				char m = a[i];
				int cnt = 0;
				while (j < a.size() && a[j] == a[i])
				{
					j ++;
					cnt ++;
				}
				if (cnt > mcnt)
				{
					mcnt = cnt;
					mc = m;
				}
				i = j - 1;
			}
			cout << (char)mc << " " << mcnt << endl;
		}
		return 0;
	}
