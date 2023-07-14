#include<bits/stdc++.h>
using namespace std;
int main()
{
	int bh,bm,eh,em;
	cin >> bh >> bm >> eh >> em;
	int h,min;
	if (eh > bh)
	{
		if (em >= bm)
		{
			h = eh - bh;
			min = em - bm;
		}
		else
		{
			h = eh - bh - 1;
			min = em + 60 - bm;
		}
	}
	else if (eh == bh)
	{
		if (em > bm) 
		{
			h = 0;
			min = em - bm;
		}
		else if (em == bm)
		{
			h = 24;
			min = 0;
		}
		else 
		{
			h = 23;
			min = em + 60 - bm;
		}
	}
	else // eh < bh 
	{
		if (em >= bm)
		{
			h = 24 + eh - bh;
			min = em - bm;
		}
		else
		{
			h = 24 + eh - bh - 1;
			min = em + 60 - bm;
		}
	}
	printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)",h,min); 
	return 0;
}
