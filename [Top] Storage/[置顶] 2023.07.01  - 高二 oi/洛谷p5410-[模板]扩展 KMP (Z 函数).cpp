#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e7 + 10;
string a, b;
int nxt[N], ext[N];
LL ansa, ansb;

void prework() {
	int p = 1, mxp = 0;
	while (mxp + 1 < b.size() and b[mxp + 1] == b[mxp]) mxp ++;
	nxt[0] = b.size(), nxt[1] = mxp;
	for (int i = 2, j; i < b.size(); ++ i) {
		mxp = p + nxt[p] - 1;
		if (i + nxt[i - p] <= mxp) nxt[i] = nxt[i - p];
		else {
			j = max(0, mxp - i + 1);
			while (i + j < b.size() and b[i + j] == b[j]) j ++;
			nxt[i] = j;
			p = i;
		}
	}
}

void exkmp() {
	int p = 0, mxp = 0;
	while (mxp < a.size() and mxp < b.size() and a[mxp] == b[mxp]) mxp ++;
	ext[0] = mxp;
	for (int i = 1, j; i < a.size(); ++ i) {
		mxp = p + ext[p] - 1;
		if (i + nxt[i - p] <= mxp) ext[i] = nxt[i - p];
		else {
			j = max(0, mxp - i + 1);
			while (i + j < a.size() and j < b.size() and a[i + j] == b[j]) j ++;
			ext[i] = j;
			p = i;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> a >> b;
	prework(); exkmp();
	for (int i = 0; i < b.size(); ++ i)
		ansa ^= (LL)(i + 1) * (nxt[i] + 1);
	for (int i = 0; i < a.size(); ++ i)
		ansb ^= (LL)(i + 1) * (ext[i] + 1);
	cout << ansa << '\n' << ansb << '\n';
	return 0;
}
