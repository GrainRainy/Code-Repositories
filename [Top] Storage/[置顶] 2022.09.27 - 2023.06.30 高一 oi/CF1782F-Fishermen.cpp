#include <iostream>
#include <cstring>
#include <vector>
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
const int M = N * N;
int n, tmp[N];
vector<LL> nodes;
LL ans;
// basic things
int head[N * N << 1], idx;
struct node{
	int nxt, to;
}edge[M << 1];
// graph
int match[M], cnt;
bool st[M];
// mathc on graph 

inline void add(int a, int b){
	edge[++ idx].nxt = head[a];
	edge[idx].to = b;
	head[a] = idx;
	return;
}

bool find(int u){
	for (int i = head[u]; ~i; i = edge[i].nxt){
		int j = edge[i].to;
		if (st[j]) continue;
		st[j] = true;
		if (!match[j] or find(match[j])){
			match[j] = u;
			return true;
		}
	}
	return false;
}

int main(){
	memset(head, -1, sizeof head);
	// init 
	input(n);
	for (int i = 1; i <= n; i ++){
		input(tmp[i]);
		for (int j = 1; j <= n; j ++){
			nodes.push_back(j * tmp[i]);
		}
	}
	// input
	sort(nodes.begin(), nodes.end());
	nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
	int index = nodes.size();
	for (int i = 1; i <= n; i ++){
		for (int j = 1; j <= n; j ++){
			int pos = lower_bound(nodes.begin(), nodes.end(), tmp[i] * j) - nodes.begin() + 1;
			add(pos, i);
		}
	}
	for (int i = 1; i <= index and cnt <= n; i ++){
		if (find(i)){
			ans += nodes[i - 1];
			cnt ++;
			memset(st, 0, sizeof st);
			// clean when match seccessfully 
		}
	}
	cout << ans << endl;
//	for (auto x : nodes){
//		cout << x << " ";
//	}
//	cout << endl;
	return 0;
}
