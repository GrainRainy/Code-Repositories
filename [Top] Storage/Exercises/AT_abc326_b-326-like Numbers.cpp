#include <bits/stdc++.h>
using namespace std;
int x;

bool judge(int x) {
	int a = x % 10; x /= 10;
	int b = x % 10; x /= 10;
	int c = x % 10;
	return b * c == a;
}

int main() {
	cin >> x;
	for (; !judge(x); ++ x); 
	cout << x << '\n';
}
