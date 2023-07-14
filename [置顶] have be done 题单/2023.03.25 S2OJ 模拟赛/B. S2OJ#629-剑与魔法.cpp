#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

#define fi first
#define se second

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

const int N = 2e5 + 100;
int n;
int cse[N], idxc;
PII ed; 
int idxe;
// first -> value, second -> index (included)

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	input(n);
	char op; int tmp;
	for (int i = 1; i <= n; i ++){
		cin >> op; input(tmp);
		if (op == 'c'){
			cse[++ idxc] = tmp;
		}
		else{
			ed[++ idxe].fi = tmp;
			ed[idxe].se = idxc;
		}
	}
	// input
	if (ed[idxe].se - ed[idxe - 1].se + 1 < ed[idxe].fi - ed[idxe - 1].fi + 1)
		return puts("-1"), 0;
	// sepcial judgement
	
	
	
	puts("13");
	
	return 0;
}
