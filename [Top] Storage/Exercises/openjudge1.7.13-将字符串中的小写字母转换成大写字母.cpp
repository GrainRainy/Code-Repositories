#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n; 
	while( (n = getchar()) != '\n')
	{
		if(n >= 'a' && n <= 'z')
		{
			n = n - 32;
			cout << (char)n;	
		} 
		else cout << (char)n;
	}
	return 0;
}
