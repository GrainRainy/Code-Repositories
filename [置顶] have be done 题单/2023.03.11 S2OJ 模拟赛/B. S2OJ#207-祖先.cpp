#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;
using LL  = long long;
using UI = unsigned int;

template <typename T> inline void input(T &x)
{
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

const int N = 1e5 + 10;
const int K = 20; // logn ~
static int n, m, k;
static UI seed1, seed2;
static UI tseed = 0, ans = 0, mul = 1;
// basic things
int h[N], idx;
struct node
{
	int nxt, to;
}edge[N << 1];
// node
queue<int> q;
int dist[N];
int father[N][K + 10];
// double increase (?)

inline void add(int a, int b)
{
	edge[++ idx].to = b;
	edge[idx].nxt = h[a];
	h[a] = idx;
}

inline void init()
{
	q.push(1);
	dist[1] = 1;
	
	while (q.size())
	{
		auto t = q.front(); q.pop();
		
		for (int i = h[t]; ~i; i = edge[i].nxt)
		{
			int j = edge[i].to;
			if (dist[j] > dist[t] + 1)
			{
				dist[j] = dist[t] + 1;
				father[j][0] = t;
				for (int k = 1; k <= K; k ++)
					father[j][k] = father[father[j][k - 1]][k - 1];
				q.push(j);
			}
		}
	}
}

inline int jump(int x, int step)
{
	for (int k = K; k >= 0; k --)
	{
		if ((1 << k) <= step)
		{
			x = father[x][k];
			step -= (1 << k);
		}
	}
	return x;
}

int main()
{
//	freopen("ancester2.in", "r", stdin);
	// i can't past protest #2 but i can do nothing /kk
	
	memset(h, -1, sizeof h);
	memset(dist, 0x3f, sizeof dist);
	// do not forget to init ohh ~
	input(seed1), input(seed2);
	input(n), input(m), input(k);
	
	for(int i = 0; i < n - 1; i ++)
	{
		int a, b;
		input(a), input(b);
		add(a, b), add(b, a);
	}
	
	init();
	// just like lca ~
	// but i found that `dist` is of no use /kk
	
	while (m --)
	{
		static int x, d;
		x = (tseed = (tseed * seed1 + seed2) ^ ans) % n + 1;
		d = (tseed = (tseed * seed1 + seed2) ^ ans) % k;
		ans = ans + mul * jump(x, d) + seed2;
		mul = mul * seed2;
	}
	
	printf("%u\n", ans);
	return 0;
}
