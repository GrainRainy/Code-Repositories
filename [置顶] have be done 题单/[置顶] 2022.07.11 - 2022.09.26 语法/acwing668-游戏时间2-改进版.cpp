#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	int bm,em;
	bm = a * 60 + b;
	em = c * 60 + d;
	int time;
	int ansh,ansm;
	
	if (bm < em) time = em - bm;
	else if (bm == em) time = 1440;
	else time = em + 1440 - bm;
	
	ansh = time / 60;
	ansm = time % 60;
	printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)",ansh,ansm);
	return 0;
}
