#include <bits/stdc++.h>

using namespace std;

const int N = 1e7;

int len;
char a[N], b[N];
int n, m;

void add()
{
	for (int i = n; a[-- i] != '0' && (a[i] = '0') || !(a[i] = '1'); );
}

void sub()
{
	for (int i = n; a[-- i] != '1' && (a[i] = '1') || !(a[i] = '0'); );
}

void mul()
{
	a[n ++] = '0';
}

void div()
{
	a[-- n] = '\0';
}

int main()
{
	cin >> n >> m >> a >> b;
	
	for (int i = 0; i < m; i ++)
	{
		char op = b[i];
		if (op == '+') add();
		else if (op == '-') sub();
		else if (op == '*') mul();
		else div();
	}
	
	cout << a << endl;
	
	return 0;
}
