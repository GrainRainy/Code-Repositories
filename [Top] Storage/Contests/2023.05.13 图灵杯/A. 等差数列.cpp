#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
using LL = long long;

template <typename T> inline void input(T &x) {
	x = 0; char c = getchar();
	bool f = false;
	for (; !isdigit(c); c = getchar())
		f |= (c == '-');
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

const int N = 5e5 + 10;
int n;
int nums[N];
vector<int> a, b, ept;
int pa, pb, EptCnt;
map<int, bool> st;

bool judge() {
	int p;
	
	if (a.size() >= 2) {
		p = a[1] - a[0];
		for (int i = 1; i < a.size(); i ++) {
			if (a[i] - a[i - 1] != p) return false;
		}
	}
	
	if (b.size() >= 2) {
		p = b[1] - b[0];
		for (int i = 1; i < b.size(); i ++) {
			if (b[i] - b[i - 1] != p) return false;
		}
	}
	return true;
}

bool dfs(int idx) {
	if (idx == n + 1) return judge();
	
	if (!pa or nums[idx] - a.back() == pa) {
		a.push_back(nums[idx]);
		if (a.size() >= 2) pa = abs(a[a.size() - 1] - a[a.size() - 2]);
		if (dfs(idx + 1)) return true;
		a.pop_back();
		if (a.size() < 2) pa = 0;
	}
	
	if (!pb or nums[idx] - b.back() == pb) {
		b.push_back(nums[idx]);
		if (a.size() >= 2) pa = abs(a[a.size() - 1] - a[a.size() - 2]);
		if (dfs(idx + 1)) return true;
		b.pop_back();
		if (a.size() < 2) pa = 0;
	}
	
	return false;
}

void solve() {
	a.clear(), b.clear(), ept.clear();
	pa = pb = EptCnt = 0;
	st.clear();
	
	int spj = -1;
	
	input(n);
	for (int i = 1; i <= n; i ++) {
		input(nums[i]);
		st[nums[i]] = true;
		spj = max(spj, nums[i]);
	}

    if (dfs(1)) return puts("Yes"), void();
    return puts("No"), void();
}

int main() {
	int t; input(t);
	while (t --) solve();
	return 0;
}
