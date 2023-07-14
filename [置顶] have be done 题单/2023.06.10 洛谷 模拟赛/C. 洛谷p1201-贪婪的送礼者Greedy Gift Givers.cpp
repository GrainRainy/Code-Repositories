#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int n, tot, per;
string tmp, nme[N];
map<string, int> mp;
map<string, int> ori;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> nme[i];
	for (int i = 1; i <= n; ++ i) {
		cin >> tmp >> tot >> per;
		ori[tmp] = tot;
		if (!per) continue;
		mp[tmp] += tot - (tot / per) * per;
		for (int j = 1; j <= per; ++ j) {
			cin >> tmp;
			mp[tmp] += tot / per;
		}
	}
	for (int i = 1; i <= n; ++ i) {
		cout << nme[i] << ' ';
		cout << mp[nme[i]] - ori[nme[i]] << endl;
	}
	return 0;
}
