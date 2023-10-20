#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
bool st[N];
deque<pair<int, int>> q;

void bfs() {
	q.push_back({1, 1}), st[1] = true;
	while (q.size()) {
		auto u = q.front(); q.pop_front();
		if (!u.first) cout << u.second << '\n', exit(0);
		if (!st[u.first * 10 % n]) {
			st[u.first * 10 % n] = true;
			q.push_front({u.first * 10 % n, u.second});
		}
		if (!st[(u.first + 1) % n]) 
			q.push_back({(u.first + 1) % n, u.second + 1});
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n, bfs();
	return 0;
}
