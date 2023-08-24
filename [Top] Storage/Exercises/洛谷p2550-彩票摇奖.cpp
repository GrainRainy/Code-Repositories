#include <bits/stdc++.h>
using namespace std;
int a[7];
int prize[7];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < 7; i ++)
		cin >> a[i];
	
	while (n --)
	{
		int cnt = 0;
		for (int k = 0; k < 7; k ++)
		{
			int b;
			cin >> b;
			for (int i = 0; i < 7; i ++)
				if (a[i] == b) cnt ++;
		}
		switch(cnt)
		{
			case 1 : prize[6] ++; break;
			case 2 : prize[5] ++; break;
			case 3 : prize[4] ++; break;
			case 4 : prize[3] ++; break;
			case 5 : prize[2] ++; break;
			case 6 : prize[1] ++; break;
			case 7 : prize[0] ++; break;
		}
	}
	
	for (int i = 0; i < 7; i ++)
		cout << prize[i] << " ";
	
	return 0;
}
