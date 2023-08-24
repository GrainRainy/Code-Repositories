#include <bits/stdc++.h>
namespace IO {
	template <typename T> inline void input(T &x) {
		x = 0; char c = getchar();
		bool f = false;
		for (; !isdigit(c); c = getchar()) f |= (c == '-');
		for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
		if (f) x = -x;
	}
	template <typename T> inline void output(T x, char ed = '\n') {
		if (x < 0) putchar('-'), x = -x;
		static short st[20], top;
		do st[++ top] = x % 10, x /= 10; while (x);
		while (top) putchar(st[top --] | '0');
		putchar(ed);
	}
}

using namespace IO;
using namespace std;

const int N = 4e4 + 10;
const int SQN = 2e2 + 10;
int n, m, l, r, ans, bl, br;
int ary[N], lis[N];
int mxT, bCnt, bLen;
int cnt[SQN][N], f[SQN][SQN];
int st[N];

int main() {
//	freopen("test.in", "r", stdin);
//	freopen("test.out", "w", stdout);
	input(n), input(m);
	bLen = sqrt(n), bCnt = (n - 1) / bLen + 1;
	for (int i = 1, tmp; i <= n; ++ i) {
		input(tmp);
		ary[i] = lis[i] = tmp;
	}
	sort(ary + 1, ary + 1 + n);
	mxT = unique(ary + 1, ary + 1 + n) - ary - 1;
	for (int i = 1; i <= n; ++ i)
		lis[i] = lower_bound(ary + 1, ary + 1 + mxT, lis[i]) - ary;
	for (int i = 1; i <= bCnt; ++ i) {
		for (int j = 1; j <= mxT; ++ j) cnt[i][j] += cnt[i - 1][j];
		for (int j = (i - 1) * bLen + 1; j <= min(i * bLen, n); ++ j) 
			cnt[i][lis[j]] ++;
	}
	for (int i = 1; i <= bCnt; ++ i)
		for (int j = i; j <= bCnt; ++ j) {
			int tmpmx = f[i][j - 1];
				for (int k = (j - 1) * bLen; k <= min(j * bLen, n); ++ k) {
					int now = cnt[j][lis[k]] - cnt[i - 1][lis[k]];
					int pre = cnt[j][tmpmx] - cnt[i - 1][tmpmx];
					if (now > pre or now == pre and lis[k] < tmpmx) 
						tmpmx = lis[k];
				}
			f[i][j] = tmpmx;
		}
	// prework
	while (m --) {
		input(l), input(r);
		l = (l + ans - 1) % n + 1;
		r = (r + ans - 1) % n + 1;
		if (l > r) swap(l, r);
		bl = (l - 1) / bLen + 1, br = (r - 1) / bLen + 1;
		int tmpmx = 0;
		if (br - bl <= 1) {
			for (int i = l; i <= r; ++ i) st[lis[i]] ++;
			for (int i = l; i <= r; ++ i)
				if (st[lis[i]] > st[tmpmx] or st[lis[i]] == st[tmpmx] and lis[i] < tmpmx)
					tmpmx = lis[i];
			for (int i = l; i <= r; ++ i) st[lis[i]] = 0;
		} else {
			for (int i = l; i <= bl * bLen; ++ i) st[lis[i]] ++;
			for (int i = r; i > (br - 1) * bLen; -- i) st[lis[i]] ++;
			tmpmx = f[bl + 1][br - 1];
			for (int i = l; i <= bl * bLen; ++ i) {
				int pre = st[tmpmx] + cnt[br - 1][tmpmx] - cnt[bl][tmpmx];
				int now = st[lis[i]] + cnt[br - 1][lis[i]] - cnt[bl][lis[i]];
				if (now > pre or now == pre and tmpmx > lis[i])
					tmpmx = lis[i];
			}
			for (int i = r; i > (br - 1) * bLen; -- i) {
				int pre = st[tmpmx] + cnt[br - 1][tmpmx] - cnt[bl][tmpmx];
				int now = st[lis[i]] + cnt[br - 1][lis[i]] - cnt[bl][lis[i]];
				if (now > pre or now == pre and tmpmx > lis[i])
					tmpmx = lis[i];
			}
			for (int i = l; i <= bl * bLen; ++ i) st[lis[i]] = 0;
			for (int i = r; i > (br - 1) * bLen; -- i) st[lis[i]] = 0;
		}
		ans = ary[tmpmx];
		output(ans);
	}
	return 0;
}
