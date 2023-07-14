#include <iostream>
#include <cstring>
using namespace std;

const int N = 5e5 + 10;
int n, ans;
int p[N << 1];
char tmp[N], s[N << 1];

int init() {
	int pos = 0;
	s[++ pos] = '$', s[++ pos] = '#';
	for (int i = 0; i < n; ++ i) 
		s[++ pos] = tmp[i], s[++ pos] = '#';
	s[++ pos] = '^';
	return pos;
}

void manacher() {
	int mid = 0, mr = 0;
	for (int i = 1; i < n; ++ i) {
		p[i] = i < mr ? min(p[(mid << 1) - i], mr - i) : 0;
		while (s[i - p[i] + 1] == s[i + p[i] + 1]) {
			p[i] ++;
			if (s[i] == '#' and !(p[i] % 4))
				if (p[i - p[i] / 2] >= p[i] / 2 and s[i - p[i] / 2] == '#')
					ans = max(ans, p[i]);
		}
		if (i + p[i] > mr) mr = i + p[i], mid = i;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> tmp;
	n = init();
	manacher();
	cout << ans << endl;
	return 0;
}
