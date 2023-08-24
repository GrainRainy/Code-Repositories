#include <iostream>
#include <cstring>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;
using PDD = pair<double, double>;

template <typename T> inline void input(T &x){
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

const int N = 110;
int n;
PDD q[N];
double ans = 1e8; 

double random(double l, double r){
	return (double)rand() / RAND_MAX * (r - l) + l;
}

double dist(PDD a, PDD b){
	double dx = a.first - b.first;
	double dy = a.second - b.second;
	return sqrt(dx * dx + dy * dy);
}

double calc(PDD p){
	double res = 0;
	for (int i = 1; i <= n; i ++)
		res += dist(p, q[i]);
	ans = min(ans, res);
	return res;
}

void simulate_anneal(){
	PDD cur(random(0, 10000), random(0, 10000));
	for (double t = 1e4; t >= 1e-4; t *= 0.99){
		PDD np;
		np.first = random(cur.first - t, cur.first + t);
		np.second = random(cur.second - t, cur.second + t);
		
		double dt = calc(np) - calc(cur);
		if (exp(-dt / t) > random(0, 1)) cur = np;
	}
}

int main(){
	srand(time(0));
	input(n);
	for (int i = 1; i <= n; i ++)
		scanf("%lf%lf", &q[i].first, &q[i].second);
	
	for (int i = 1; i <= 100; i ++)
		simulate_anneal();
//	cout << (int)ans << endl;
	printf("%.0lf", ans);
	return 0;
}
