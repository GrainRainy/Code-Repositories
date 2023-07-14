#include <bits/stdc++.h>
using namespace std;

template <typename T> inline void output(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top -- ] | '0');
	putchar(ed);
}

const int N = 1e8;
const double INF = 1e-8;
int n;
int st[N], top;
double a, b, delta;

inline bool judge(int t) {
    a = n - t * 0.5;
    b = n - t;
    delta = a / b;
    if (fabs((int)delta - (double)delta) < INF) return true;
    return false;
}

int main() {
	scanf("%d", &n);
	for (int t = 1; t < n; ++ t) {
		if (judge(t)) st[ ++ top] = t;
	}
	
	output(top, ' ');
    for (int i = 1; i <= top; ++ i) 
        output(st[i], ' ');
    puts("");
    return 0;
}
