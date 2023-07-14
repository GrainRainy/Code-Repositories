#include<bits/stdc++.h>
using namespace std;
char a[100],b[100],c[100]; 
char str1[100] = {'v','e','r','t','e','b','r','a','d','o'};
char str2[100] = {'a','v','e'};
char str3[100] = {'c','a','r','n','i','v','o','r','o'};
char str4[100] = {'o','n','i','v','o','r','o'};
char str5[100] = {'i','n','s','e','t','o'};
char str6[100] = {'h','e','m','a','t','o','f','a','g','o'};
int main()
{
	scanf("%s",a);
	scanf("%s",b);
	scanf("%s",c);
	
	if (strcmp(a,str1) == 0)
	{
		if (strcmp(b,str2) == 0)
		{
			if (strcmp(c,str3) == 0) cout << "aguia";
			else cout << "pomba";
		}
		else 
		{
			if (strcmp(c,str4) == 0)	cout << "homem";
			else cout << "vaca";
		}
	}
	else
	{
		if (strcmp(b,str5) == 0)
		{
			if (strcmp(c,str6) == 0) cout << "pulga";
			else cout << "lagarta";
		}
		else
		{
			if (strcmp(c,str6) == 0) cout << "sanguessuga";
			else cout << "minhoca";
		}
	}
}
