#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

template <typename T> inline void input(T &x) {
	x = 0;
	char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

const int N = 10000;
LL n, m, ans = 0x7fffffffffffffff;
struct Person {
	int to, co;

	bool operator < (const Person &t) const {
		return co < t.co;
	}
} per[N];

int sum[N], save_sum[N];
bool st[N];

int main() {
	input(n), input(m);
	for (int i = 1; i <= n; i ++) {
		input(per[i].to), input(per[i].co);
		sum[per[i].to] ++, save_sum[per[i].to] ++;
	}
	// input

	sort(per + 1, per + n + 1);

	int t[3005];
	LL cnt,vote;
	ans = 0x7fffffffffffffff;
	for(int i = save_sum[1]; i <= n; i ++) {
		memset(st, 0, sizeof(st));
		memset(t, 0, sizeof(t));
		cnt = vote = 0;
		for(int j = 1; j <= n; j ++) {
			if(per[j].to == 1) {
				vote ++, st[j] = 1;
				continue;
			}
			if(sum[per[j].to] - t[per[j].to] >= i) {
				cnt += per[j].co, st[j] = 1, t[per[j].to] ++, vote ++;
			}
		}
		int j = 1;
		while(vote<i) {
			if(!st[j]) cnt += per[j].co, vote ++;
			j++;
		}
		ans=min(ans,cnt);
	}
	cout << ans << endl;
	return 0;
}
