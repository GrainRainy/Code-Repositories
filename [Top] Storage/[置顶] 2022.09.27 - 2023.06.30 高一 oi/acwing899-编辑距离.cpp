#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e3 + 10;
const int LEN = 15;

int n, m;
char s[N][LEN];
int f[LEN][LEN];
char tmp[LEN];
int limit;

int edit_distance(char str1[], char str2[])
{
	int na = strlen(str1 + 1), nb = strlen(str2 + 1);
	
	for (int j = 0; j <= nb; j ++) f[0][j] = j;
	for (int i = 0; i <= na; i ++) f[i][0] = i;
	
	for (int i = 1; i <= na; i ++)
		for (int j = 1; j <= nb; j ++)
		{
			f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
			f[i][j] = min(f[i][j], f[i - 1][j - 1] + (str1[i] != str2[j]));
		}
		
	return f[na][nb];
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i ++)
		cin >> s[i] + 1;
	
	while (m --)
	{
		int res = 0;
		cin >> tmp + 1 >> limit;
		
		for (int i = 0; i < n; i ++)
			if (edit_distance(s[i], tmp) <= limit) res ++;
			
		cout << res << endl;
	}
	
	return 0;
	
}
