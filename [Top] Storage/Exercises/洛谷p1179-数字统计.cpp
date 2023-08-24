#include <bits/stdc++.h>

using namespace std;

int times2(int n)
{
	int in_cnt = 0;//count
	int num;//数位上的数 
	while(n)
	{
		num = n % 10;
		if (num == 2) in_cnt ++;
		n = n / 10;
	}
	return in_cnt;
}

int main()
{
	int beg, end;
	cin >> beg >> end;
	int out_cnt = 0;
	for (int i = beg; i <= end; i ++)
		out_cnt += times2(i);
	
	cout << out_cnt << endl;
	return 0;
}
