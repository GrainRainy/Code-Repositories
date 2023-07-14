#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int, int> PII;

const int N = 110;
int n, m;
int map[N][N], d[N][N];
// map�洢��ͼ��d�洢ÿһ���㵽���ľ��� 
PII q[N * N];
// ģ�����
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
// λ��ƫ������
PII Prev[N][N];


int bfs()
{
	int hh = 0,  tt = 0;
	q[0] = {0, 0};
	// ���г�ʼ��
	memset(d, -1, sizeof d);
	// ��ʼ��Ϊ -1 �ĵ��ʾû���߹� 
	d[0][0] = 0;
	
	while (hh <= tt)
	// ���в��� 
	{
		auto t = q[hh ++];
		
		for (int i = 0; i < 4; i ++)
		{
			int x = t.first + dx[i], y = t.second + dy[i];
			if (x >= 0 && x < n && y >= 0 && y < m && !map[x][y] && d[x][y] == -1)
			{
				d[x][y] = d[t.first][t.second] + 1;
				Prev[x][y] = t;
				q[ ++ tt ] = {x, y};
			}
		}
	}
	
	return d[n - 1][m - 1];
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			cin >> map[i][j];
	
	cout << bfs() << endl;
	
	return 0;
}
