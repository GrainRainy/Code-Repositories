#include <iostream>

using namespace std;
typedef long long LL;

const int N = 50;
int stk[N + 10], tt;
LL tmp;

int main()
{
	char c;
	while ((c = getchar()) != '@')
	{
		if (c >= '0' && c <= '9')
			tmp *= 10, tmp += c - '0';
			
		else if (c == '.')
			stk[++ tt] = tmp, tmp = 0;
			
		else if (c == '+')
		{
			LL x = stk[tt --];
			LL y = stk[tt --];
			stk[++ tt] = x + y;
		}

		else if (c == '-')
		{
			LL x = stk[tt --];
			LL y = stk[tt --];
			stk[++ tt] = y - x;
		}
		
		else if (c == '*')
		{
			LL x = stk[tt --];
			LL y = stk[tt --];
			stk[++ tt] = x * y;
		}
		
		else if (c == '/')
		{
			LL x = stk[tt --];
			LL y = stk[tt --];
			stk[++ tt] = (double)y / (double)x;
		}
	}
	cout << stk[tt] << endl;
	return 0;
}
