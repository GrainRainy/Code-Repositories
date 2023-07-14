#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	cin >> a >> b;
	
	int time;
	if (b > a) time = b - a;
	else time = b + 24 - a;
	
	printf("O JOGO DUROU %d HORA(S)",time); 
	return 0;
} 
