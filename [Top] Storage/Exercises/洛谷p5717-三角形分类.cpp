#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int e,f,g,h;
	int k=(a>b)?a:b;
	e=(k>c)?k:c;//longest
	f=a+b+c-e;//Á½¶Ì±ßÖ®ºÍ 
	int z=(a<b)?a:b;
	g=(z<c)?z:c;//shortest
	h=f-g;//medium
	if(f<=e)
		cout<<"Not triangle"<<endl;
	else
	{
		if(pow(g,2)+pow(h,2)>pow(e,2))
		cout<<"Acute triangle"<<endl;
		else if(pow(g,2)+pow(h,2)==pow(e,2))
		cout<<"Right triangle"<<endl;
		else if(pow(g,2)+pow(h,2)<pow(e,2))
		cout<<"Obtuse triangle"<<endl;
		if(a==b||b==c||c==a)
		cout<<"Isosceles triangle"<<endl;
		if(a==b&&b==c)
		cout<<"Equilateral triangle"<<endl;
	}
	
	return 0; 
}
