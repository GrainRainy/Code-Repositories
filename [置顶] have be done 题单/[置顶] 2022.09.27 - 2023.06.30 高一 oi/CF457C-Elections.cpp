#include <iostream>
#include <cstring>
#include <algorithm>

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

const int N = 1e5 + 10;
LL n, m;
struct Person{
	int to, co;
	
	bool operator < (const Person &t) const{
		return co < t.co;
	}
}per[N];

int sum[N];
bool st[N];

inline LL check(int i)
{
	int t[N];
	LL cnt,vote;
	LL ans = 0x7fffffffffffffff;
	
	memset(st, 0, sizeof(st));
	memset(t, 0, sizeof(t));
	cnt = vote = 0;
	for(int j = 0; j < n; j ++){
		if(per[j].to == 0){
			vote ++, st[j] = 1;
			continue;
		}
		if(sum[per[j].to] - t[per[j].to] >= i){
			cnt += per[j].co, st[j] = 1, t[per[j].to] ++, vote ++;
		}
	}
	int j = 0;
	while(vote < i){
		if(!st[j]) cnt += per[j].co, vote ++;
		j ++;
	}
	return cnt;
}

int main()
{
	input(n);
	for (int i = 0; i < n; i ++){
		input(per[i].to), input(per[i].co);
		sum[per[i].to] ++;
	}
	// input
	
	sort(per, per + n);
	
	int l = sum[0], r = n;
	while(l <= r){
		int mid = l + r >> 1;
		if (check(mid) < check(mid+1)) r = mid-1;
		else l = mid + 1 ;
	}
	cout << check(l) << endl;
	return 0;
}
