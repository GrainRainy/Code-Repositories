#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

typedef pair<int, int> P;

const int N = 100000;

int n;
vector<P> segs; // ��ʾ�������� 

void merge (vector<P> &segs)
{
	
	vector<P> ans;
	// ���ڴ洢�ϲ������Ľ�� 
	sort(segs.begin(), segs.end());
	// sort �� pair��������ʱ���ȸ���first�ؼ��������ٸ���second�ؼ�������
	int st = -2e9, ed = -2e9;
	// ������Ŀ���ݷ�Χ�������߽�ֵ
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
	// ѭ���ϲ����� 
	if (st != -2e9) ans.push_back({st, ed});
	// ��segs�п� 
	segs = ans;
	// �������� 
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
	// ����
	
	merge(segs);
	// �ϲ����䴦�� 
	for (int i = 0; i < segs.size(); i ++)
		cout << segs[i].first << " " << segs[i].second << endl;
	return 0; 
}
