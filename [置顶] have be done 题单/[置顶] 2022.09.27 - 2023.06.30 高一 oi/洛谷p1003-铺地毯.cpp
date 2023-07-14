#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int draw[N][4];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> draw[i][0] >> draw[i][1] >> draw[i][2] >> draw[i][3];
	// input
	int x, y;
	cin >> x >> y;
	for (int i = n; i > 0; i --)
	{
		int ba = draw[i][0], bb = draw[i][1];
		int ea = ba + draw[i][2] - 1, eb = bb + draw[i][3] - 1;
		if (x >= ba && x <= ea && y >= bb && y <= eb)
		{
			cout << i << endl;
			return 0;
		}
		if (i == 1) cout << -1 << endl;
	}
	
	return 0;
}
