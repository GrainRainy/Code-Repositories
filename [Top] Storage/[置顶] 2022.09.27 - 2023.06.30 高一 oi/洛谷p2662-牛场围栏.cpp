#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>

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

const int N = 3e5 + 100;
const int M = 5e6 + 100;

int n, m;
int nums[N]; // input
int stick[N], cnt; // sum
bool ton[N];
// basic things
int head[N], idx;
struct node{
	int nxt, to, w;
}edge[M << 1];
// graph 
priority_queue<PII, vector<PII>, greater<PII>> heap;
int st[N], dist[N];
// shortest path

inline void add(int a, int b, int c){
	edge[++ idx].to = b;
	edge[idx].nxt = head[a];
	edge[idx].w = c;
	head[a] = idx;
}

inline void djikstra(int root){
	dist[root] = 0;
	heap.push({0, root});
	
	while (heap.size()){
		auto t = heap.top(); heap.pop();
		int distance = t.first;
		int index = t.second;
		
		if (st[index]) continue;
		st[index] = true;
		for (int i = head[index]; ~i; i = edge[i].nxt){
			int j = edge[i].to;
			if (dist[j] > distance + edge[i].w){
				dist[j] = distance + edge[i].w;
				heap.push({dist[j], j});
			}
		}
	}
}

int main(){
	memset(dist, 0x3f, sizeof dist);
	memset(head, -1, sizeof head);
	// init
	
	input(n), input(m);
	int tmp_min = 0x3f3f3f3f;
	for (int i = 0; i < n; i ++)
		input(nums[i]), tmp_min = min(nums[i], tmp_min);
	// input
	
	int tmp_gcd = nums[0];
	for (int i = 1; i < n; i ++)
		tmp_gcd = __gcd(tmp_gcd, nums[i]);
	if (tmp_gcd != 1 or tmp_min - m <= 1) return puts("-1"), 0;
	// special judge
	
	for (int i = 0; i < n; i ++)
		for (int j = 0; j <= m; j ++){
			if (nums[i] - j > 0 and !ton[nums[i] - j]){
				ton[nums[i] - j] = true;
				stick[++ cnt] = nums[i] - j;
			}
		}
	// split stick 
	for (int i = 0; i < tmp_min; i ++)
		for (int j = 1; j <= cnt; j ++)
			add(i, (i + stick[j]) % tmp_min, stick[j]);
	
	djikstra(0);
	
	int ans = -1;
	for (int i = 1; i <= tmp_min - m; i ++)
		ans = max(ans, dist[i] - tmp_min);
	cout << ans << endl;
	return 0;
}
