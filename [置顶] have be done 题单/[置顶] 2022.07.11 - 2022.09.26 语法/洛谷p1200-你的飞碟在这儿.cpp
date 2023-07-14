#include<bits/stdc++.h>
using namespace std;
char a[10],b[10];
int main()
{
	scanf("%s",a+1);
	scanf("%s",b+1);
	int lengtha=strlen(a+1);
	int lengthb=strlen(b+1);
	int suma=1,sumb=1;
	for(int i=1;i<=lengtha;i++)
	{
		suma=suma*(a[i]-'A'+1);
	}
	for(int i=1;i<=lengthb;i++)
	{
		sumb=sumb*(b[i]-'A'+1);
	}
	int ansa,ansb; 
	ansa=suma%47;
	ansb=sumb%47; 
	if(ansa==ansb) cout<<"GO";
	else cout<<"STAY";
	return 0;
}
