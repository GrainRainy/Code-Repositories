#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>

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

const int N = 1e5 + 10;
int a[10], n, b[N], top;
map<int, int> cnt;
int ans = 0x3f3f3f3f;

struct Save {
    int val, idx;
    bool operator < (const Save &t) const {
        return val < t.val;
    }
}save[N * 6];

int main() {
    for (int i = 1; i <= 6; ++ i) input(a[i]);
    input(n);
    for (int i = 1; i <= n; ++ i) input(b[i]), cnt[b[i]] ++;
    
    if (cnt.size() == 1) return puts("0") & 0;
    cnt.clear();

    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= 6; ++ j) {
            save[++ top] = {b[i] - a[j], i};
        }
    }
    sort(save + 1, save + 1 + top);

    int lp = 1, rp = 0, tmpcnt = 0;
    while (rp < top) {
    	if (!cnt[save[++ rp].idx]) tmpcnt ++;
    	cnt[save[rp].idx] ++;
    	
    	while (lp < rp and save[rp].val - save[lp].val >= ans) {
    		if (cnt[save[lp].idx] == 1) tmpcnt --;
    		cnt[save[lp].idx] --;
    		++ lp;
		}
		while (lp < rp and tmpcnt == n) {
			ans = min(ans, save[rp].val - save[lp].val);
			if (cnt[save[lp].idx] == 1) tmpcnt --;
			cnt[save[lp].idx] --;
			++ lp;
		}
	}
	printf("%d\n", ans);
    return 0;
}
