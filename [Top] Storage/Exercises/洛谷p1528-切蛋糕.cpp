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

const int N = 50 + 10;
const int M = 1024 + 10;

int n, m;
int cake[N], mouth[M];
int pfm[M]; // perfix sum of mouth 
int sum, maxc;
// basic things
int tc, nc; // total cake and needed cake 
int wc;  // waste cake 
// dfs optimisation

bool SubDfs(int test, int origin){
	if (!test) return true;
	if (tc - wc < nc) return false;
	// special judgement 
	
	bool judge = false; 
	for (int i = origin; i <= n; ++ i){
		if (cake[i] >= mouth[test]){
			tc -= mouth[test];
			nc -= mouth[test];
			cake[i] -= mouth[test];
		
		bool waste = false;
		if (cake[i] < mouth[1]){
			wc += cake[i];
			waste = true;
		}
		if (mouth[test] == mouth[test - 1]){
			if (SubDfs(test - 1, i)) judge = true;
		}
		else if (SubDfs(test - 1, 1)) judge = true;
		
		if (waste) wc -= cake[i];
	
		cake[i] += mouth[test];
		tc += mouth[test];
		nc += mouth[test];
		
		if (judge) return true;
		}
	}
	return false;
}

inline bool dfs(int test){
	tc = sum;
	nc = pfm[test];
	wc = 0;
	
	return SubDfs(test, 1);
}

int main(){
	input(n);
	for (int i = 1; i <= n; i ++){
		input(cake[i]);
		maxc = max(maxc, cake[i]);
		sum += cake[i];
	}
	input(m);
	for (int i = 1; i <= m; i ++){
		input(mouth[i]);
	}
	sort(mouth + 1, mouth + 1 + m);
	for (int i = 1; i <= m; i ++)
		pfm[i] = pfm[i - 1] + mouth[i];
	// input and init
	
	int l = 1, r = m, mid;
	while (mouth[r] > maxc) -- r;
	while (l < r){
		mid = l + r + 1 >> 1;
		if (dfs(mid)) l = mid;
		else r = mid - 1;
	}
	cout << r << endl;
	return 0;
}
