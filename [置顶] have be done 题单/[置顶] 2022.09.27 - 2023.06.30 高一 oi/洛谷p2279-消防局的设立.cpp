#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

template <typename T> inline void input(T &x){
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

const int N = 1e3 + 10;
const int INF = 1e8 + 10;
int n, ans;
int idx[N], father[N];
int dist[N], depth[N];

inline bool cmp(int a, int b){
	return depth[a] > depth[b];
}

int main(){
	input(n);
	idx[0] = 0, father[0] = 0, dist[0] = INF, depth[0] = 0;
	idx[1] = 1, father[1] = 0, dist[1] = INF, depth[1] = 0;
	for (int i = 2; i <= n; ++ i){
		input(father[i]);
		depth[i] = depth[father[i]] + 1;
		idx[i] = i;
		dist[i] = INF;
	}
	sort(idx + 1, idx + n + 1, cmp);
	for (int i = 1; i <= n; ++ i){
		int cur = idx[i], fa = father[cur], gf = father[fa];
		
		dist[cur] = min(min(dist[cur], dist[fa] + 1), dist[gf] + 2);
		if (dist[cur] > 2){
			dist[gf] = 0, ans ++;
			int ggf = father[gf], gggf = father[ggf];
			dist[ggf] = min(dist[ggf], 1);
			dist[gggf] = min(dist[gggf], 2);
		}
	}
	cout << ans << endl;
	return 0;
}
