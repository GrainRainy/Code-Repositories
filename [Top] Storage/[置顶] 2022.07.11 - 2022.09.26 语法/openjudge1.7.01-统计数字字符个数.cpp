#include<bits/stdc++.h>
using namespace std;
char a[260];
int main()
{
	char c;
	int ans=0;
	while((c=getchar())!='\n')
	{
		if(c>='0'&&c<='9') ans++;
	}
	cout<<ans<<endl;
	return 0;
}	

