#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

const int N = 1001000;

int h[N], idx;
struct node{
	int to, nxt, w;
}edge[N];

int n, m;
int dist[N];
bool st[N]; 

priority_queue<PII, vector<PII>, greater<PII> > heap;
// ˫�ؼ��֣��ڵ��С�Լ��ڵ��� 

void add(int a, int b, int c)
{
	edge[++ idx].to = b;
	edge[idx].w = c;
	edge[idx].nxt = h[a];
	h[a] = idx;
}

void dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	
	heap.push({0, 1});
	while (heap.size())
	{
		PII t = heap.top();
		heap.pop();
		int ver = t.second; // �ڵ���
		int distance = t.first; // ����
		
		if (st[ver]) continue;
		// ���Ѿ�ȷ���õ�����·��ʱ������ǰ�����д洢��Ԫ�����ֱ࣬���������� 
		st[ver] = true;
		for (int i = h[ver]; i != -1; i = edge[i].nxt)
		{
			int j = edge[i].to;
			if (dist[j] > distance + edge[i].w)
			{
				dist[j] = distance + edge[i].w;
				heap.push({dist[j], j});
			}
		 } 
	}

}

int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	while (m --)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}
	dijkstra();
	
		
	if (dist[n] == 0x3f3f3f3f) puts("-1");
	else cout << dist[n] << endl;
	
	return 0;
	
}
