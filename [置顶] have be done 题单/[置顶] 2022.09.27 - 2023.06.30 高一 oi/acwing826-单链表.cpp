#include <iostream>

using namespace std;

const int N = 100000;

int head, val[N + 10], Next[N + 10], idx;

void init()
{
	head = -1;
	idx = 0;
}

void add_to_head(int x)
{
	val[idx] = x;
	Next[idx] = head;
	head = idx ++;
}

void add(int k, int x)
{
	val[idx] = x;
	Next[idx] = Next[k];
	Next[k] = idx ++;
}

void remove(int k)
{
	Next[k] = Next[Next[k]];
}

int main()
{
	int m;
	cin >> m;
	
	init();
	
	while (m --)
	{
		char op;
		int k, x;
		cin >> op;
		if (op == 'H')
		{
			cin >> x;
			add_to_head(x);
		}
		else if (op == 'D')
		{
			cin >> k;
			if (!k) head = ne[head];
			remove(k - 1);
		}
		else
		{
			cin >> k >> x;
			add(k - 1, x);
		}
	}
	
	for (int i = head; i != -1; i = Next[i])
		cout << val[i] << " ";
	cout << endl;
	
	return 0;
}
