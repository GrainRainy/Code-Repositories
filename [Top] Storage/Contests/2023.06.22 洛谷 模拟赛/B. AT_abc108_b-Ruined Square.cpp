#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> a >> b >> c >> d;
	int kl = c - a, kr = d - b;
	cout << c - kr << ' ' << d + kl << ' ';
	cout << c - kl - kr << ' ' << d + kl - kr << endl;
	return 0;
}
