#include<bits/stdc++.h>
using namespace std;
int score[1005][4];
int main()
{
	int n;
	cin>>n;
	int t=0;//旗鼓相当的对手对数
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		cin>>score[i][j];
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;i+j<=n;j++)
		{
			if(abs(score[i][1]-score[i+j][1])>5) continue;
			else
			{
				if(abs(score[i][2]-score[i+j][2])>5) continue;
				else
				{
					if(abs(score[i][3]-score[i+j][3])>5) continue;
					else 
					{
						if(abs(score[i][1]+score[i][2]+score[i][3]-score[j+i][1]-score[j+i][2]-score[j+i][3])>10) continue;
						else t++;
					}
				}
			}
		}
	}
	cout<<t;
	return 0;
}
