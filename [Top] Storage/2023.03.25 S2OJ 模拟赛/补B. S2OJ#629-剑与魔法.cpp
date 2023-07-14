#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
using LL = long long;

template <typename T> inline void input(T &x){
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

int n;
LL ans;
priority_queue<LL, vector<LL>, greater<LL>> heap;

int main(){
	input(n);
	char op; LL tmp;
	for (int i = 1; i <= n; i ++){
		cin >> op; input(tmp);
		if (op == 'c'){
			heap.push(tmp);
			ans += tmp;
		}
		else{
			if (i == n){
				if (heap.size() < tmp) return puts("-1"), 0;
				else{
					while (heap.top() < 0){
						ans -= heap.top();
						heap.pop();
					}
					return cout << ans << endl, 0;
				}
			} 
			while (heap.size() >= tmp){
				ans -= heap.top();
				heap.pop();
			}
		}
	}
	cout << ans << endl;
}
