#include <bits/stdc++.h>
using namespace std;

int a[27];

int main()
{
	char s[100005];
	cin >> s;
	int len = strlen (s); //�Ż������󳤶ȶ���Ϊ����0ֹͣ�����ʡ3ms 
	for (int i = 0; i < len; i ++)
		a[s[i] - 97] ++;
	
	for (int i = 0; i < len; i ++)
		if (a[s[i] - 97] == 1)
		{
			cout << s[i];
			return 0;
		}
	cout << "no" << endl;
	return 0;
}
