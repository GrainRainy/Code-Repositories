#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

#define owo 0 

using namespace std;
using LL = long long;

const int N = 1e6 + 10;
int l, r;
LL ans = 0;
int father[N];

struct Node{
	int u, v;
	LL w;
	
	inline bool operator < (const Node &t) const{
		return w < t.w;
	}
};
vector<Node> edge;
// kruskal

int find(int x){
	if (father[x] == x) return x;
	return father[x] = find(father[x]);
}

inline bool check(int u){
	return ((u >= l) and (u <= r));
}

inline LL lcm(int a, int b){
	return (LL)a / __gcd(a, b) * b;
}

void kruskal(){
	sort(edge.begin(), edge.end());
	
	for (auto t : edge){
		int a = t.u, b = t.v;
		if (find(a) != find(b)){
			father[max(find(a), find(b))] = min(find(a), find(b));
			ans += t.w;
		}
	}
	return;
}

int main(){
	cin >> l >> r;
	for (int i = l; i <= r; ++ i)
		father[i] = i;
	// init 
	
	for (int i = 2; i <= r; ++ i){
		int index = 0;
		for (int j = i; j <= r; j += i){
			if (check(j) and !index) index = j;
			if (check(j))
				edge.push_back((Node){index, j, lcm(index, j)});
		}
		if (i >= l) edge.push_back((Node){index, l, lcm(index, l)});
	}
	kruskal();
	cout << ans << endl;
	return owo;
} 
