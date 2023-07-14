#include <iostream>

using namespace std;

const int N = 5;

string ans[N << 1], rans[N << 1], test[N];
string leftt = "freopen(\"";
string inrt = ".in\",\"r\",stdin);";
string outrt = ".out\",\"w\",stdout);";

int t, n, m;

int judge()
// 0 refers to the normal people
// 1 refers to the people who needs to visit his grandparents
// 2 refers to the people who made fun in tests
{
	for (int i = 0; i < 2 * m; i ++)
	{
		cin >> ans[i];
	}
		
	
	int tmp = 0;
	for (int i = 0; i < 2 * m; i ++)
	{
		if (ans[i] == rans[i]) continue;
		else if (ans[i].substr(0, 2) == "//" && ans[i].substr(ans[i].size() - 2, 2) == ");")
			return 1;
		else tmp = 2;
	}
	return tmp;
}

int main()
{
	cin >> t >> n >> m;
	for (int i = 0; i < m; i ++)
		cin >> test[i];
	
	for (int i = 0, j = -1; i < 2 * m; i ++)
	{
		if (i % 2 == 0) ++ j, rans[i] = leftt + test[j] + inrt;
		else rans[i] = leftt + test[j] + outrt;
	}
	// right answers
	
	while (n --)
	{
		int type = judge();
		if (type == 0) puts("PION2202 RP++.");
		else if (type == 1) puts("Wrong file operation takes you to your ancestors along with your 3 years' efforts on OI.");
		else if (type == 2) puts("Good luck and have fun.");
	}
	
	return 0;
}
