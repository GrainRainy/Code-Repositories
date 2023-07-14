#include <iostream>
#include <cstring>
#define max(a, b) ((a > b) ? a : b)
using namespace std;
using LL = long long;

const int N = 2.5e4 + 10;
int n, maxn, maxidx, idx;
string nums[N];
int son[N * 20][26];
bool cnt[N * 20];
bool ml[N * 20];
char let[N * 20];

int cnt_ans;
string ans;

void insert(string a)
{
	int step = 0;
	for (int i = 0; i < a.size(); i ++)
	{
		int u = a[i] - 'a';
		if (!son[step][u]) son[step][u] = ++ idx;
		let[son[step][u]] = a[i];
		step = son[step][u];
	}
	cnt[step] = true;
}

void init(string a)
{
	int step = 0;
	for (int i = 0; i < a.size(); i ++)
	{
		int u = a[i] - 'a';
		ml[son[step][u]] = true;
		step = son[step][u];
	}
}

void dfs(int u)
{
	if (cnt[u]) ++ cnt_ans, ans += 'P';
	if (cnt_ans == n)
	{
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i ++)
			cout << ans[i] << endl;
		return;
	}
	
	for (int i = 0; i < 26; i ++)
	{
		if (!ml[son[u][i]] and son[u][i])
		{
			ans += let[son[u][i]];
			dfs(son[u][i]);
			ans += '-';
		}
	}
	for (int i = 0; i < 26; i ++)
	{
		if (ml[son[u][i]] and son[u][i])
		{
			ans += let[son[u][i]];
			dfs(son[u][i]);
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i ++)
	{
		cin >> nums[i];
		insert(nums[i]);
		if (maxn < nums[i].size())
		{
			maxn = nums[i].size();
			maxidx = i;
		}
	}
	
	init(nums[maxidx]);
	
	dfs(0);
	
	return 0;
}
