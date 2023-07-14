#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 300000;
// n和m的 数据范围都是1e5， 那么所有坐标的和为 3 * 1e5 

typedef pair<int, int> ope; // 对于序列的操作 

int a[N + 10]; // 离散化之后的序列
int s[N + 10]; // 离散化之后序列的前缀和
vector<int> alls; // 待离散化的值
vector<ope> add, access; // 进行的操作(加，查找) 

int find(int x)
{
	int l = 0, r = alls.size() - 1;
	while(l < r)
	{
		int mid = r + l >> 1;
		if (alls[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return r + 1;
	// 从1开始将所有的数进行映射，为了便于前缀和的计算 
}
// 找到x离散化后的结果 
 
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i ++)
	{
		int x, c;
		cin >> x >> c;
		add.push_back({x, c});
		
		alls.push_back(x);
	}
	// 读入所有的插入操作
	for (int i = 0; i < m; i ++)
	{
		int l, r;
		cin >> l >> r;
		access.push_back({l, r});
		alls.push_back(l);
		alls.push_back(r);
	
	}
	// 读入所有的区间求和
	
	sort(alls.begin(), alls.end());	
	// 排序
	alls.erase(unique(alls.begin(), alls.end()), alls.end());
	// 去重
	
	for (auto item : add)
	{
		int x = find(item.first);
		a[x] += item.second;
	}
	// 进行插入操作
	for (int i = 1; i <= alls.size(); i ++)
		s[i] = s[i - 1] + a[i];
	// 计算序列的前缀和
	
	for (auto item : access)
	{
		int l = find(item.first), r = find(item.second);
		cout << s[r] - s[l - 1] << endl;
	}
	return 0;
	
}
