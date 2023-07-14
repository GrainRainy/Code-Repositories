#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

typedef pair<int, int> P;

const int N = 100000;

int n;
vector<P> segs; // 表示所有区间 

void merge (vector<P> &segs)
{
	
	vector<P> ans;
	// 用于存储合并区间后的结果 
	sort(segs.begin(), segs.end());
	// sort 对 pair进行排序时，先根据first关键字排序，再根据second关键字排序
	int st = -2e9, ed = -2e9;
	// 依据题目数据范围而定，边界值
	for (auto seg : segs) 
	{
		if (ed < seg.first)
        {
            if (st != -2e9)
            	ans.push_back({st, ed});
			st = seg.first;
			ed = seg.second;
			
        }
		else ed = max(ed, seg.second);
	}
	// 循环合并区间 
	if (st != -2e9) ans.push_back({st, ed});
	// 对segs判空 
	segs = ans;
	// 更新区间 
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i ++)
	{
		int l, r;
		cin >> l >> r;
		segs.push_back({l, r});
	}
	// 读入
	
	merge(segs);
	// 合并区间处理 
	for (int i = 0; i < segs.size(); i ++)
		cout << segs[i].first << " " << segs[i].second << endl;
	return 0; 
}
