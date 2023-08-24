#include <iostream>
#include <cstring>
using namespace std;
const int N = 5e5 + 10;
char s[N], t[N];
int n, m, cnt[6]; 
int nxt[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> s + 1 >> t + 1;
	n = strlen(s + 1), m = strlen(t + 1);
	for (int i = 1; i <= n; ++ i) cnt[s[i] - '0'] ++;
	for (int i = 1; i <= m; ++ i) cnt[t[i] - '0' + 2] ++;
	for (int i = 2, pos = 0; i <= m; ++ i) {
		while (pos and t[i] != t[pos + 1]) pos = nxt[pos];
		if (t[i] == t[pos + 1]) pos ++;
		nxt[i] = pos;
	}
	for (int i = nxt[m] + 1; i <= m; ++ i) cnt[t[i] - '0' + 4] ++;
	if (cnt[0] >= cnt[2] and cnt[1] >= cnt[3]) cout << t + 1;
	else { cout << s + 1 << endl; return 0; }
	cnt[0] -= cnt[2], cnt[1] -= cnt[3];
	while (cnt[0] >= cnt[4] and cnt[1] >= cnt[5]) {
		for (int i = nxt[m] + 1; i <= m; ++ i) cout << t[i];
		cnt[0] -= cnt[4], cnt[1] -= cnt[5];
	}
	while (cnt[0]) cout << '0', cnt[0] --;
	while (cnt[1]) cout << '1', cnt[1] --;
	return 0;
}
