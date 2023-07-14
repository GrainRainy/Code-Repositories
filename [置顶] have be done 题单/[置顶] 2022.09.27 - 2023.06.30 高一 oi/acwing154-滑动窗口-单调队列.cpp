#include <iostream>

using namespace std;

const int N = 1e6;
int nums[N], q[N];

int main()
{
	int n, k;
	cin >> n >> k;
	
	for (int i = 0; i < n; i ++)
		cin >> nums[i];
	
	int hh = 0, tt = -1;
	for (int i = 0; i < n; i ++)
	{
		if (hh <= tt && i - k + 1 > q[hh]) hh ++;
		//�ж϶�ͷ�Ƿ񻬳����� 
		while (hh <= tt && nums[q[tt]] >= nums[i]) tt --;
		// �Զ��н����ϸ񵥵��Դ��� 
		q[++ tt] = i;
		// ������� 
		if (i >= k - 1) cout << nums[q[hh]] << ' ';
		// �ж� i �Ƿ�С�����䳤�ȣ������������ 
	}
	cout << endl;
	// ��Сֵ
	
	hh = 0, tt = -1;
	for (int i = 0; i < n; i ++)
	{
		if (hh <= tt && i - k + 1 > q[hh]) hh ++;
		//�ж϶�ͷ�Ƿ񻬳����� 
		while (hh <= tt && nums[q[tt]] <= nums[i]) tt --;
		// �Զ��н��е����Դ��� 
		q[++ tt] = i;
		// ������� 
		if (i >= k - 1) cout << nums[q[hh]] << ' ';
		// �ж� i �Ƿ�С�����䳤�ȣ������������ 
	}
	cout << endl;
	// ���ֵ 
}
