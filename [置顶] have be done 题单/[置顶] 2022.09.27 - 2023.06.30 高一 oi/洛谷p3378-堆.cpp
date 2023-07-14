#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int h[N], siz;

void down(int u)
{
	int t = u;
	if (u * 2 <= siz && h[u * 2] < h[t])
		t = u * 2;
	if (u * 2 + 1 <= siz && h[u * 2 + 1] < h[t])
		t = u * 2 + 1;
	if (u != t)
	{
		swap(h[u], h[t]);
		down(t);
	}
}

void up(int u)
{
	while (u / 2 && h[u / 2] > h[u])
	{
		swap(h[u / 2], h[u]);
		u /= 2;
	}
}

void insert(int x)
{
	h[++ siz] = x;
	up(siz);
	return;
}

void print()
{
	cout << h[1] << endl;
	return;
}

void delet()
{
	h[1] = h[siz --];
	down(1);
}

int main()
{
	int n;
	cin >> n;
	int op;
	while (n --)
	{
		cin >> op;
		if (op == 1)
		{
			int tmp;
			cin >> tmp;
			insert(tmp);
		}
		else if (op == 2) print();
		else delet();
	}
	return 0;
}
