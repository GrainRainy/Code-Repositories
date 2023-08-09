#include <iostream>
#include <cstring>
#include <cctype>
#include <queue>
using namespace std;
template <typename T>
inline void input(T &x)
{
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}
template <typename T>
inline void output(T x, char ed = '\n')
{
	if (x < 0) putchar('-'), x = -x;
	static short st[30], idx;
	do st[++ idx] = x % 10, x /= 10; while (x);
	while (idx) putchar(st[idx --] | '0');
	putchar(ed);
}

typedef long long LL;
typedef pair<LL, int> PLI;
const int N = 1e5 + 10;
const int M = 3e5 + 10;
int n, m, x;
LL height[N], now_height[N];
// basic things
LL dist[N];
bool st[N];
// refers to the dots that has been to
int h[N], idx;
struct node
{
	int nxt, w, to;
}edge[M << 1];

inline void add(int a, int b, int c)
{
	edge[++ idx].to = b;
	edge[idx].w = c;
	edge[idx].nxt = h[a];
	h[a] = idx;
}

priority_queue<PLI, vector<PLI>, greater<PLI> > heap;
// save distance and index
// dijstra
void djikstra()
{
	memset(dist, 0x3f, sizeof dist);
	
	dist[1] = 0, now_height[1] = x;
	heap.push({0, 1});
	// init
	while (heap.size())
	{
		auto cur = heap.top().second;  heap.pop();
		// current index
		
		if (st[cur]) continue;
		st[cur] = true;
		for (int i = h[cur]; ~i; i = edge[i].nxt)
		{
			int target = edge[i].to, width = edge[i].w;
			if (now_height[cur] - width > height[target])
			// 直接飞过去大于目标树 target 高度, 先降高度  
			{
				if (dist[target] > dist[cur] + now_height[cur] - height[target])
				{
					dist[target] = dist[cur] + now_height[cur] - height[target];
					now_height[target] = height[target];
					heap.push({dist[target], target});
				}
			}
			else if (now_height[cur] - width < 0)
			// 飞进地里, 需要提升 width - now_height[cur] 的高度 
			{
				if (dist[target] > dist[cur] + width + width - now_height[cur])
				{
					dist[target] = dist[cur] + width + width - now_height[cur];
					now_height[target] = 0;
					heap.push({dist[target], target});
				}
			}
			else
			// 能够直接到达 
			{
				if (dist[target] > dist[cur] + width)
				{
					dist[target] = dist[cur] + width;
					now_height[target] = now_height[cur] - width;
					heap.push({dist[target], target});
				}
			}
		}
	}
	return;
}

int main()
{
	memset(h, -1, sizeof h);
	input(n), input(m), input(x);
	for (int i = 1; i <= n; ++ i)
		input(height[i]);
	for (int i = 0; i < m; ++ i)
	{
		int tmpa, tmpb;  LL tmpc;
		input(tmpa), input(tmpb), input(tmpc);
		if (height[tmpa] >= tmpc) add(tmpa, tmpb, tmpc);
		if (height[tmpb] >= tmpc) add(tmpb, tmpa, tmpc);
	}
	// input
	djikstra();
	
	cout << (dist[n] == 0x3f3f3f3f3f3f3f3f ? -1 : dist[n] + height[n] - now_height[n]) << endl;
	return 0;
}
