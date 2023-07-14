#include <bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	getline (cin , a);
	int cnt = 0;
	
	for (char c : a)
	{
		if (c >= '0' && c <= '9') cnt ++;
	}
	cout << cnt;
	return 0;
}
