#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using LL = long long;

const int N = 2e5 + 100;
int n, m;
// vector with init
int dg[N]; // degree
bool st[N];

inline bool check(int u, vector<vector<int>> &graph){
	queue<int> q;
	q.push(u), st[u] = true;
	
	bool f = true;
	while (q.size()){
		auto t = q.front(); q.pop();
		if (dg[t] != 2) f = false;
		for (int tmp : graph[t]){
			if (!st[tmp]) q.push(tmp), st[tmp] = true;
		}
	}
	return f;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> m;	
	vector<vector<int>> graph(n + 10, vector<int>());
	for (int i = 1; i <= m; i ++){
		int tmpa, tmpc; char tmpb, tmpd;
		cin >> tmpa >> tmpb >> tmpc >> tmpd;
		graph[tmpa].push_back(tmpc);
		graph[tmpc].push_back(tmpa);
		dg[tmpa] ++, dg[tmpc] ++;
	}
	// inpud
	
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i <= n; i ++){
		if (!st[i]){
			if (check(i, graph)) ans1 ++;
			else ans2 ++;
		}
	}
	
	cout << ans1 << " " << ans2 << endl;
	return 0;
}
