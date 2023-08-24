#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int l;
	l=n*5;
	int o;
	o=n*3+11;
	int a;
	a=l>o;
	if(a==1)
		printf("%s","Luogu");
	else
		printf("%s","Local");
	return 0;
}
