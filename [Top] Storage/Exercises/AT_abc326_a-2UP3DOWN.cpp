#include <bits/stdc++.h>
using namespace std;
int x, y;
int main() {
	cin >> x >> y;
	if (x - y >= 0 and x - y <= 3) puts("Yes");
	else if (y - x >= 0 and y - x <= 2) puts("Yes");
	else puts("No");
}
