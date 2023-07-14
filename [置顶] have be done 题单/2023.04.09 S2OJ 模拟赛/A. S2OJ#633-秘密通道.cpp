#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <ctime>

using namespace std;
using LL = long long;
using PII = pair<int, int>;

template <typename T> inline void input(T &x){
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

const int N = 5e2 + 100;
int n, m;
int sta, ed;
char gph[N][N];

int head[N * N], idx;
struct Node{
	int nxt, to, w;
}edge[N * N << 3];
// graph
int tmp[4];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
// position
bool st[N * N];
int dist[N * N];
priority_queue<PII, vector<PII>, greater<PII>> heap;
// shortest path 

inline void add(const int &a, const int &b, const int &c){
	edge[++ idx].nxt = head[a];
	edge[idx].to = b;
	edge[idx].w = c;
	head[a] = idx;
}

inline int getPos(const int &x, const int &y){
	return (x - 1) * m + y;
}

inline void shootTo(int x, int y){
	int now = getPos(x, y);
	int tmpx = x, tmpy = y;
	int minDist = 0x3f3f3f3f;
	// left
    while(gph[tmpx][tmpy] != '#') tmpy --;
	tmp[0] = getPos(tmpx, tmpy + 1), minDist = min(minDist, y - tmpy);
    tmpy = y;
	// right
	while(gph[tmpx][tmpy] != '#') tmpy ++;
	tmp[1] = getPos(tmpx, tmpy - 1), minDist = min(minDist, tmpy - y);
    tmpy = y;
	// up
	while(gph[tmpx][tmpy] != '#') tmpx --;
	tmp[2] = getPos(tmpx + 1, tmpy), minDist = min(minDist, x - tmpx);
    tmpx = x;
	// down
	while(gph[tmpx][tmpy] != '#') tmpx ++;
	tmp[3] = getPos(tmpx - 1, tmpy), minDist = min(minDist, tmpx - x);
		
	add(now, tmp[0], minDist);
	add(now, tmp[1], minDist);
	add(now, tmp[2], minDist);
	add(now, tmp[3], minDist);
}

void djikstra(){
	dist[sta] = 0;
	heap.push({0, sta});
	while (heap.size()){
		int ver = heap.top().second;
		heap.pop();
		
		if (st[ver]) continue; st[ver] = true;
		for (int i = head[ver]; ~i; i = edge[i].nxt){
			int j = edge[i].to;
			if (dist[j] > dist[ver] + edge[i].w){
				dist[j] = dist[ver] + edge[i].w;
				heap.push({dist[j], j});
			}
		}
	}
}

int main(){
	memset(head, -1, sizeof head);
	memset(dist, 0x3f, sizeof dist);
	// init 
	input(n), input(m);
	for (int i = 1; i <= n; ++ i){
		cin >> gph[i] + 1;
	}
	// input 
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= m; ++ j){
			if (gph[i][j] == '#') continue;
			if (gph[i][j] == 'C') sta = getPos(i, j);
			if (gph[i][j] == 'F') ed = getPos(i, j);
			
			shootTo(i, j);
			for (int k = 0; k < 4; ++ k){
				int ni = i + dx[k], nj = j + dy[k];
				if (gph[ni][nj] != '#') 
					add(getPos(i, j), getPos(ni, nj), 1);
			}
		}
	}
	// add 
	djikstra();
	if (dist[ed] == 0x3f3f3f3f) puts("nemoguce");
	else cout << dist[ed] << endl;
	return 0;
}
