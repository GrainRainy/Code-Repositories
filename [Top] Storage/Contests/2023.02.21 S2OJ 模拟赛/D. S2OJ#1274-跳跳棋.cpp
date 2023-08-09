#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int x, y, z;
queue<pair<int, int> > q;

bool check()
{
	if (a == x and b == y and c == z) return true;
	if (a == x and b == z and c == y) return true;
	if (a == y and b == x and c == z) return true;
	if (a == y and b == z and c == x) return true;
	if (a == z and b == y and c == x) return true;
	if (a == z and b == x and c == y) return true;
	return false;
}

bool judge(int u, int mid) 
{
	int none = 0;
	if (a != u and a != mid) none = a;
	if (b != u and b != mid) none = b;
	if (c != u and c != mid) none = c;
	
	
	if (u < mid)
		if (u < none and (mid << 1) - u > none) return false;
	else
		if (u > none and (mid << 1) - u < none) return false;
	return true;
}

//void bfs(int u, int mid)
//// u 点相对于 mid跳 
//{
//	q.push({u, mid});
//	
//	
//	while (q.size())
//	{
//		auto t = q.front(); q.pop();
//		
//		if ()
//	}
//}

int main()
{
	cin >> a >> b >> c >> x >> y >> z;
	if (check())
	{
		cout << "YES" << endl << "0" << endl;
		return 0;
	}
	else puts("NO");
	return 0;
}
