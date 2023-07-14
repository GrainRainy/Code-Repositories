#include <iostream>
#include <cstring>

using namespace std;
using LD = long double;

int n;
string s;
LD ans, len; 

int main() {
	cin >> n >> s;
	for (int i = 0; i < s.size(); ++ i) {
		if (s[i] == 'o') {
			ans += 2 * len + 1;
			len += 1;
		}
		if (s[i] == 'x') len = 0;
		if (s[i] == '?') {
			ans += len + 0.5;
			len = (len + 1) / 2;
		}
	}
	printf("%.4Lf\n", ans);
	return 0;
}
