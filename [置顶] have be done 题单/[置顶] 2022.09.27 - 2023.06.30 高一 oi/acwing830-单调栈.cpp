#include <iostream>

using namespace std;

const int N= 1e5; 
int n;
int stk[N + 10], tt;
int main()
{
	ios :: sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i ++)
	{
		int tmp;
		cin >> tmp;
		while (tt && stk[tt] >= tmp) tt --;
		if (!tt) cout << "-1" << ' ';
		else 	 cout << stk[tt] << ' ';
		
		stk[++ tt] = tmp;
	}
	
}
