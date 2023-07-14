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

const int N = 5e4 + 100;
LL n, g;
struct Station{
	LL dist, val;
	
	bool operator < (const Station &t) const{
		return dist < t.dist;
	}
}sta[N];
LL res, ans;

void solve(int u){
	if (u == n) return;
	
	int ti = u + 1; // target index
	for (int i = u + 1; sta[i].dist - sta[u].dist <= g and i <= n; ++ i){
		if (sta[i].val < sta[u].val){
			LL delta = sta[i].dist - sta[u].dist;
			if (delta < res){
				ans += delta * sta[u].val;
				res -= delta;
			}
			else{
				ans += (delta - res) * sta[u].val;
				res = 0;
			}
			 
			return solve(i), void();
		}
		if (sta[ti].val > sta[i].val) ti = i;
	}
	ans += (g - res) * sta[u].val;
	res = g - (sta[ti].dist - sta[u].dist);
	return solve(ti), void();
}

int main(){
	input(n), input(g), input(res), input(sta[++ n].dist);
	for (int i = 1; i < n; ++ i)
		input(sta[i].dist), input(sta[i].val);
	// input
	sort(sta + 1, sta + 1 + n);
	for (int i = 1; i <= n; i ++)
		if (sta[i].dist - sta[i - 1].dist > g) return puts("-1"), 0;
	// init and special judgement
	int ti = 1; 
	for (int i = 1; sta[i].dist <= res and i <= n; ++ i){
		if (sta[ti].val > sta[i].val) ti = i;
	}
	res -= sta[ti].dist;
	// find the first target index
	solve(ti);
	cout << ans << endl;
	return 0;
}
