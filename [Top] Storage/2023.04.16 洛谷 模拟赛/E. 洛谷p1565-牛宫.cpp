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

const int N = 210;

int n, m;
int graph[N][N];
int sum[N][N];
double ans = 0;
int anssiz = 1;

void calc(int a, int b, int c, int d){
	int siz = (c - a + 1) * (d - b + 1);
	int tmpsum = sum[c][d] - sum[a - 1][d] - sum[c][b - 1] + sum[a - 1][b - 1];
	double tmpans = tmpsum * 1.0 / siz;
	if (ans < tmpans){
		ans = tmpans, anssiz = siz;
	}
	return;
}

int main(){
	input(n), input(m);
	for (int i = 1; i <= n; i ++){
		for (int j = 1; j <= m; j ++){
			input(graph[i][j]);
			sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + graph[i][j];
		}
	}
	
	for (int i =1 ; i <= n; i ++){
		for (int j = 1; j <= m; j ++){
			for (int u = i; u <= n; u ++){
				for (int v = i; v <= m; v ++){
					calc(i, j, u, v);
				}
			}
		}
	}
	
//	for (int i = 1; i <= n; i ++){
//		for (int j = 1; j <= m; j ++){
//			for (int u = 1; u <= i; u ++){
//				for (int v = 1; v <= j; v ++){
//					calc(u, v, i, j);
//				}
//			}
//		}
//	}
	cout << anssiz << endl;
}
