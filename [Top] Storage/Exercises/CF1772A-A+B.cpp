#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;
using LL = long long;

int a, b;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t --){
		cin >> a >> b;
		printf("%d\n", a + b);
	}
	return 0;
}
