#include <bits/stdc++.h>
using namespace std;
string a, b;
int main() {
	cin >> a >> b;
	for (int i = 1; i < a.size(); i ++){
		if (a == b) return puts("Yes"), 0;
		a = a.substr(1) + a[0];
	}
	puts("No");
	return 0;
}
