#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int h[N], siz;
int ph[N], hp[N];
// ph[k] = n; ��ʾ�� k ����������±�Ϊ n
// hp[k] = n; ��ʾ�������е� k ��Ԫ���ǵڼ�������ĵ� 
void heap_swap(int a, int b)
{
	swap(ph[hp[a]], ph[hp[b]]);
	swap(hp[a], hp[b]);
	swap(h[a], h[b]);
}

void down(int u)
{
	int t = u;
	// t ��ʾ��ǰ�ڵ�������ӽڵ�����Сֵ���±� 
	if (u * 2 <= siz && h[u * 2] < h[t])
		t = u * 2; 
	if (u * 2 + 1 <= siz && h[u * 2 + 1] < h[t])
		t = u * 2 + 1;
	if (u != t)
	{
		heap_swap(u, t);
		down(t);
	}
}

void up(int u)
{
	while (u / 2 && h[u / 2] > h[u])
	{
		heap_swap(u / 2, u);
		u /= 2;
	}
}

int main()
{
	int n;
	int cnt = 0;
	cin >> n;
	while (n --)
	{
		char op[10];
		int k, x;
		cin >> op;
		
		if (!strcmp(op, "I"))
		{
			cin >> x;
			cnt ++, siz ++;
			// ����
			ph[cnt] = siz, hp[siz] = cnt;
			h[siz] = x;
			up(siz); 
		}
		
		else if (!strcmp(op, "PM"))
			cout << h[1] << endl;
		
		else if (!strcmp(op, "DM"))
		{
			heap_swap(1, siz);
			siz --;
			down(1);
		}
		
		else if (!strcmp(op, "D"))
		{
			cin >> k;
			k = ph[k];
			heap_swap(k, siz);
			siz --;
			down(k), up(k);
		}
		
		else if (!strcmp(op, "C"))
		{
			cin >> k >> x;
			k = ph[k];
			h[k] = x;
			down(k), up(k);
		}
	}
	return 0;
}

