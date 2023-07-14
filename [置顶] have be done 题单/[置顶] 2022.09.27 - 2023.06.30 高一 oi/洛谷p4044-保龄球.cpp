#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <random>

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

const int N = 50 + 10;
int n, m;
PII a[N];
int ans = -1;

int calc(){
	int res = 0;
	for (int i = 0; i < m; i ++){
		res += a[i].first + a[i].second;
		if (i < n){
			if (a[i].first == 10){
				res += a[i + 1].first + a[i + 1].second;
			}
			else if (a[i].first + a[i].second == 10){
				res += a[i + 1].first;
			}
		}
	}
	ans = max(ans, res);
	return res;
}

void simulate_anneal(){
	for (double t = 1e4; t > 1e-4; t *= 0.99){
		int x = rand() % m;
		int y = rand() % m;
		int ori = calc();
		swap(a[x], a[y]);
		if (n + (a[n - 1].first == 10) == m){
			int lat = calc();
			if (exp((lat - ori) / t) < (double)rand() / RAND_MAX){
				swap(a[x], a[y]);
			}
		}
		else swap(a[x], a[y]);
	}
}


int main(){
	input(n);
	for (int i = 0; i < n; i ++){
		input(a[i].first), input(a[i].second);
	}
	if (a[n - 1].first == 10){
		input(a[n].first), input(a[n].second);
		m = n + 1;
	}
	else m = n;
	
	int times = 100;
	while (times --){
		simulate_anneal();
	}
	cout << ans << endl;
	return 0;
}
