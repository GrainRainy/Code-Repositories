#include <iostream>
#include <cstring>

using namespace std;

const int N = 510;

int map[N][N];
// �ڽӾ����ͼ
int n, m;
int dist[N];
// �洢��ľ��� 
bool st[N]; 
// �洢�Ѿ�ȷ����̾���ĵ� 

int dijkstra()
{	
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	
	for (int i = 0; i < n; i ++)
	// ���� n �������· 
	{
		int t = -1;
		for (int j = 1; j <= n; j ++)
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		// ���¿���չ�����·�� 
		st[t] = true;
		// t ��ȷ����Сֵ�����Ϊ���
		for (int j = 1; j <= n; j ++)
			dist[j] = min(dist[j], dist[t] + map[t][j]);
		// ʹ�� t ���µ���̱߽��и���
		
	}
	if (dist[n] == 0x3f3f3f3f) return -1;
		// �����޽� 
		return dist[n]; 
}

int main()
{
	cin >> n >> m;
	memset(map, 0x3f, sizeof map);
	
	while (m --)
	{
		int a, b, c;
		cin >> a >> b >> c;
		map[a][b] = min(map[a][b], c);
		// �����ر����Ի� 
	}
	
	int t = dijkstra();
	
	cout << t << endl;
	
	return 0;
	
}
