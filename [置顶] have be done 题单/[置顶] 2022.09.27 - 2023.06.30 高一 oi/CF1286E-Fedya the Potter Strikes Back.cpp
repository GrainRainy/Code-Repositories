#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
template <typename T>
void input(T &x)
{
	x = 0; char c = getchar(); int f = 0;
	for (; !isdigit(c); c = getchar())
		f |= c == '-';
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}
template <typename T>
void output(T x, char ed = '\n')
{
	if (x < 0) putchar('-'), x = -x;
	static short st[30], tp;
	do st[++ tp] = x % 10, x /= 10; while (x);
	while (tp) putchar(st[tp --] | '0');
	putchar(ed);
}
// so as to input __int128

const int N = 6e5 + 10, MASK = (1 << 30) - 1;

LL nxt[N], anc[N], nums[N];
LL stk[N], idx;
// ¦Ì£¤¦Ì¡Â?? 
__int128 ans, sum;

map<LL, LL> cnt;

LL query(int u)
{
	LL* p = lower_bound(stk + 1, stk + 1 + idx, u);
	return nums[*p];
}
// ¦Ì£¤¦Ì¡Â???t¡¤? 

signed main()
{
	LL n; input(n);
	char c = getchar(); string s;
	input(nums[0]);
	s += c, ans = nums[0];
	output(nums[0]);
	// 3?¨º??¡¥
	stk[++ idx] = 0;
	// ¦Ì£¤¦Ì¡Â??3?¨º??¡¥
	
	for (int i = 1, j = 0; i < n; i ++)
	{
		c = getchar(), input(nums[i]);
		c = (c - 'a' + ans % 26) % 26 + 'a', s += c;
		nums[i] = nums[i] ^ (ans & MASK);
		// ?a?¨¹ 
		while (j && (c != s[j])) j = nxt[j];
		if (s[j] == c) j ++;
		nxt[i + 1] = j;
		if (c == s[nxt[i]]) anc[i] = anc[nxt[i]]; 
		else anc[i] = nxt[i];
		// ¨¬? KMP
		for (int k = i; k > 0;)
		{
			if (s[k] == c) k = anc[k];
			else 
			{
				int v = query(i - k);
				cnt[v] --, sum -= v;
				// ?¨¹D? border ?¡¥o?D??¡é¡ê????¡è¡Á?D??¦Ì
				if (!cnt[v]) cnt.erase(v);
				k = nxt[k];
			}
		}
		if (s[0] == c) cnt[nums[i]] ++, sum += nums[i];
		while (idx && nums[i] <= nums[stk[idx]]) idx --;
		stk[++ idx] = i;
		int ncnt = 0;
		for (auto it = cnt.upper_bound(nums[i]);it != cnt.end();)
		{
			sum -= (it -> first - nums[i])*it->second;
			ncnt += it -> second;
			auto j = next(it);
			cnt.erase(it);
			it = j;
		}
		cnt[nums[i]] += ncnt;
		ans += nums[stk[1]] + sum;
		output(ans);
	}
	return 0;
}

/*
## ?¨´¡À????¡¤

?¡¥¨¬????¡è border ?¡¥o?D??¡é¡ê?2?¨¨? c ¨º¡À?¨¹D? border ¨°??¡ã¡Á?D??¦Ì 
¦Ì£¤¦Ì¡Â?????¡è border ?¨¦¨°¨¦D??¡é 
 
*/
