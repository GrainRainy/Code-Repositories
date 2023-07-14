#include <bits/stdc++.h>
using namespace std;
char mw[105],yw[105],fy[105];//1~n 
char letter[30];//1~26
bool flag[27] = {1};//1~26
int main()
{
	gets(mw + 1);
	gets(yw + 1);
	gets(fy + 1);
	int length = strlen(yw + 1);
	for (int i = 1;i <= length;i++)
	{
		if(letter[mw[i] - 'A'+1] == 0)
		{
			letter[mw[i] - 'A' + 1] = yw[i]; 
			flag[mw[i] - 'A' + 1] = 1;
		} 
		if(letter[mw[i] - 'A' + 1] != 0 && letter[mw[i] - 'A' + 1] != yw[i])
			{cout << "Failed"; return 0;}
		//if(letter[mw[i] - 'A' + 1] != 0 && yw[i] != letter[mw[i] - 'A' + 1])
			//{cout << "Failed"; return 0;}
	}
	for (int i = 1;i <= 26;i++)
	{
		if(flag[i] == 0) 
			{cout << "Failed"; return 0;}
	}

	int l = strlen(fy + 1);
	for(int i = 1;i <= l;i++)
		cout << letter[fy[i] - 'A' + 1];
	return 0;
}

