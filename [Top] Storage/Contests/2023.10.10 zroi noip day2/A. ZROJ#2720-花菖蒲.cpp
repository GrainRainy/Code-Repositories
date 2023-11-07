#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a, b, ttp = 1, top;
struct Edge { int a, b; }edge[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> a >> b;
	if (!a and !b) return puts("1") & 0;
	if (b > a - 2 or (a - b) == 3) return puts("0") & 0;
	int u = 1;
	while (b --) {
		edge[++ top] = {u, ++ ttp}, u = ttp;
		edge[++ top] = {u, ++ ttp}, a --;
	}
	edge[++ top] = {u, ++ ttp}, a --;
	while (a --) edge[++ top] = {1, ++ ttp};
	cout << ttp << '\n';
	for (int i = 1; i <= top; ++ i)
		cout << edge[i].a << ' ' << edge[i].b << '\n';
	return 0;
}
