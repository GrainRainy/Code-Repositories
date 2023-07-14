#include <iostream>
#include <cstring>
#include <algorithm>

namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x; 
	}
}

using namespace IO;
using namespace std;
using UI = unsigned int;
#define int unsigned int
const int N = 1e6 + 10;
const int M = 6;
int n, m, p, k, hit[4];
UI ans;
int state[(1 << M) + 10], top;

struct Matrix {
	UI a[(1 << M) + 10][(1 << M) + 10], mx, my;
	
	UI * operator [](int x) { return a[x]; }
	Matrix(int n, int m) { 
		mx = n, my = m; 
        for (int i = 1; i <= mx; ++ i)
            for (int j = 1; j <= my; ++ j)
                a[i][j] = 0;
	}
	
	Matrix operator * (Matrix t) {
		Matrix res(mx, t.my);
		for (UI i = 1; i <= mx; ++ i)
			for (UI k = 1; k <= my; ++ k)
				for (UI j = 1; j <= t.my; ++ j)
					res[i][j] = (res[i][j] + a[i][k] * t[k][j]);
		return res;
	}
	
	inline void build() {
		for (int i = 1; i <= mx; ++ i) a[i][i] = 1;
	}
};

int move(int s, int x) {
	if (p <= x) return s << x - p;
	return s >> p - x;
}

bool prework(int s) {
	for (int i = 0; s >> i; ++ i) {
		if (!((s >> i) & 1)) continue;
		if (s & move(hit[2], i + k) & (((1 << m) - 1) ^ (1 << i)))
			return false;
	}
	return true;
}

bool judge(int x, int y) {
    for(int i = 0; i < m; ++ i) {
    	if (!((x >> i) & 1)) continue;
        if(y & move(hit[3], i + k)) return false;
    }     
    for(int i = 0; i < m; ++ i) {
    	if (!((y >> i) & 1)) continue;
        if(x & move(hit[1], i + k)) return false;
    }    
    return true;
}

Matrix qpow(Matrix a, int b) {
	Matrix res(a.mx, a.my); res.build();
	while (b) {
		if (b & 1) res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

signed main() {
	input(n), input(m), input(p), input(k), k ++;
	for (int i = 1; i <= 3; ++ i)
		for (int j = 1, tmp; j <= p; ++ j)
			input(tmp), hit[i] <<= 1, hit[i] |= tmp;
	
	for (int i = 0; i < (1 << m); ++ i)
		if (prework(i)) state[++ top] = i;
	
	Matrix ori(top, top);
	for (int i = 1; i <= top; ++ i)
		for (int j = 1; j <= top; ++ j)
			ori[i][j] = judge(state[i], state[j]);
	
	Matrix res = qpow(ori, n - 1);		
	int ans = 0;
	for (int i = 1; i <= top; ++ i)
		for (int j = 1; j <= top; ++ j)
			ans += res[i][j];
	cout << ans << endl;
	return 0;
}
