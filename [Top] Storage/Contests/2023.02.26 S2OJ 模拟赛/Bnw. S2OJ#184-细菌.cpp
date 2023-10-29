#include <iostream>
#include <cstring>
#define max(a, b) (a > b ? a : b)
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

typedef long long LL;
const int N = 110;
int n;
int gph[N][N];
// basic things
LL queue[N], hh, tt;
// queue
LL dist[N];
bool st[N];
// spfa

void spfa()
{
	memset(dist, 0x3f, sizeof dist); // init
	queue[hh] = n;
	dist[n] = 1, st[n] = true; // push dots n 
	
	while (hh <= tt)
	{
//		auto t = q.front(); q.pop();
//		st[t] = false;
		auto t = queue[hh ++]; st[t] = false;

		for (int i = 1; i <= n; i ++)
		{
//			cout << (bool)gph[t][i] << " " << (dist[i] > max(1ll, (dist[t] + gph[t][i] + 1) / 2)) << " ";
//			cout << (bool)(gph[t][i] && dist[i] > max(1ll, (dist[t] + gph[t][i] + 1) / 2)) << '\n';
			if (gph[t][i] && dist[i] > max(1ll, (dist[t] + gph[t][i] + 1) / 2))
			{
				dist[i] = max(1ll, (dist[t] + gph[t][i] + 1) / 2);
				if (!st[i]) queue[++ tt] = i, st[i] = true;
			}
		}
	}
}

int main()
{
	input(n);
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j)
			input(gph[j][i]), gph[j][i] = -gph[j][i]; // ½¨·´Í¼  
	// input
	spfa();
	printf("%ld", dist[1]);
	return 0;
}
