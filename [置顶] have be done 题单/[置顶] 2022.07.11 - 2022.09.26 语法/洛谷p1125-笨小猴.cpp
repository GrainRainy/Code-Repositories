#include<bits/stdc++.h>
using namespace std;
bool prime(int n)
{
	bool flag = false;
	for(int i = 2;i <= sqrt(n);i ++)
	{
		if(n % i == 0) flag = 1;//not prime
	}
	return flag;
}
int cnt[105];
char word[105];
int main()
{
	gets(word + 1);
	int length = strlen(word + 1);
	for(int i = 1 ;i <= length;i++)
		cnt[word[i] - 96]++;
	int maxn = 0,minn = 105;
	for(int i = 1;i <= 26;i++)
	{
		if(cnt[i] > maxn && cnt[i] != 0) maxn = cnt[i];
		if(cnt[i] < minn && cnt[i] != 0) minn = cnt[i];
	}
	int ans=maxn-minn;
	if(prime(ans) == 1 || ans == 0 || ans == 1) cout << "No Answer" << endl << "0"; 
	else cout << "Lucky Word" << endl << ans;
	return 0;
}

