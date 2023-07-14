#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n --)
	{
		string p1, p2;
		cin >> p1 >> p2;
		if (p1 == "Hunter" && p2 == "Gun" || p1 == "Gun" && p2 =="Bear" || p1 == "Bear" && p2 == "Hunter")
			cout << "Player1" << endl;
		else if (p1 == p2) cout << "Tie" << endl;
		else cout << "Player2" << endl;
	}
	return 0;
}
