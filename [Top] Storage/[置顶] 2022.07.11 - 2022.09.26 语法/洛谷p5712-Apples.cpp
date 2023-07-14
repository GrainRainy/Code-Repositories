#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x;
	scanf("%d",&x); 
	if(x==0)
		printf("%s","Today, I ate 0 apple.");
	else if(x==1)
		printf("%s","Today, I ate 1 apple.");
	else
		printf("%s%d%s","Today, I ate ",x," apples.");
	return 0;	
}
