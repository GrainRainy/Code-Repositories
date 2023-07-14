#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 300000;
// n��m�� ���ݷ�Χ����1e5�� ��ô��������ĺ�Ϊ 3 * 1e5 

typedef pair<int, int> ope; // �������еĲ��� 

int a[N + 10]; // ��ɢ��֮�������
int s[N + 10]; // ��ɢ��֮�����е�ǰ׺��
vector<int> alls; // ����ɢ����ֵ
vector<ope> add, access; // ���еĲ���(�ӣ�����) 

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
	// ��1��ʼ�����е�������ӳ�䣬Ϊ�˱���ǰ׺�͵ļ��� 
}
// �ҵ�x��ɢ����Ľ�� 
 
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
	// �������еĲ������
	for (int i = 0; i < m; i ++)
	{
		int l, r;
		cin >> l >> r;
		access.push_back({l, r});
		alls.push_back(l);
		alls.push_back(r);
	
	}
	// �������е��������
	
	sort(alls.begin(), alls.end());	
	// ����
	alls.erase(unique(alls.begin(), alls.end()), alls.end());
	// ȥ��
	
	for (auto item : add)
	{
		int x = find(item.first);
		a[x] += item.second;
	}
	// ���в������
	for (int i = 1; i <= alls.size(); i ++)
		s[i] = s[i - 1] + a[i];
	// �������е�ǰ׺��
	
	for (auto item : access)
	{
		int l = find(item.first), r = find(item.second);
		cout << s[r] - s[l - 1] << endl;
	}
	return 0;
	
}
