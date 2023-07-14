#include <iostream>

using namespace std;

string a, b;
int lena, lenb;
int f[2010][2010];

int main()
{
	cin >> a >> b;
	lena = a.size();
	lenb = b.size();	
	
	for (int i = 1; i <= lena; i ++) f[i][0] = i;
	for (int i = 1; i <= lenb; i ++) f[0][i] = i;
	
	for (int i = 1; i <= lena; i ++)
		for (int j = 1; j <= lenb; j ++)
		{
			if (a[i - 1] == b[j - 1]) 
				f[i][j] = f[i - 1][j - 1];
			else
				f[i][j] = min(f[i - 1][j], min(f[i][j - 1], f[i - 1][j - 1])) + 1;
		}
		
	cout << f[lena][lenb] << endl;
	
	return 0;
}
