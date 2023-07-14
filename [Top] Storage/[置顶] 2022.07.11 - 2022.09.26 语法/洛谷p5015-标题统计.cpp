#include <bits/stdc++.h>

using namespace std;

int main()
{
	char c;
	int cnt = 0;
	while(scanf("%c", &c) != EOF)
	{
		if (c != 10 && c != ' ')
			cnt ++;
	}
	cout << cnt << endl;
	return 0;
}
