#include <bits/stdc++.h>
#define enter putchar('\n')

using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;

template <typename T> inline void input(T &x) {
	x = 0; char c = getchar(); bool f = false;
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
	if (f) x = -x;
}
template <typename T, typename... Args> void input(T &x, Args&... args) {
	input(x), input(args...);
}
template <typename T> inline void output(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[20], top;
	do st[++ top] = x % 10, x /= 10; while (x);
	while (top) putchar(st[top --] | '0');
	putchar(ed);
}

string a, b;
int la, lb;
int sta[30], stb[30]; 

bool judge(int a) {
	bool f = false;
	f |= (a == 'a' - 'a');
	f |= (a == 't' - 'a');
	f |= (a == 'c' - 'a');
	f |= (a == 'o' - 'a');
	f |= (a == 'd' - 'a');
	f |= (a == 'e' - 'a');
	f |= (a == 'r' - 'a');
	return f;
}

int main() {
	cin >> a >> b;
	for (auto t : a) {
		if (t != '@') sta[t - 'a'] ++;
		else la ++;
	}
	for (auto t : b) {
		if (t != '@') stb[t - 'a'] ++;
		else lb ++;
	}
	
	for (int i = 0; i < 26; i ++) {
		if (sta[i] < stb[i]) {
			if (judge(i)) la -= stb[i] - sta[i];
			else return puts("No"), 0;
		}
		if (sta[i] > stb[i]) {
			if (judge(i)) lb -= sta[i] - stb[i];
			else return puts("No"), 0;
		}
	}
	if (la < 0 or lb < 0) puts("No");
	else puts("Yes");
	return 0;
}
