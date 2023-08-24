#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N = 2e5;
int n, k;
int dist[N];
queue<int> q;
bool check(int x)
{
	return (x >= 0 and x < N);
}
int bfs(int u)
{
	q.push(u); dist[u] = 0;
	while (q.size())
	{
		auto t = q.front(); q.pop();
		if (t == k) return dist[t];
		if (check(t + 1) and dist[t + 1] == -1)
            dist[t + 1] = dist[t] + 1, q.push(t + 1);
        if (check(t - 1) and dist[t - 1] == -1)
            dist[t - 1] = dist[t] + 1, q.push(t - 1);
        if (check(t * 2) and dist[t * 2] == -1)
            dist[t * 2] = dist[t] + 1, q.push(t * 2);
	}
	return -1;
}
int main()
{
	memset(dist, - 1, sizeof dist);
	cin >> n >> k;
	cout << bfs(n) << endl;
	return 0;
}
