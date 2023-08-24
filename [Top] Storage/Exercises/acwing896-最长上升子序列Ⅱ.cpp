#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N], q[N];
// a[] ���ڴ洢���� 
// p[] ����ά�����в�ͬ���ȵ�����������н�βԪ�ص���Сֵ 

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	// input
	int len = 0;
	// �洢��ǰ����������еĳ��ȣ��� q �����е�Ԫ�ظ��� 
	q[0] = -2e9;
	for (int i = 0; i < n; i ++)
	{
		int l = 0, r = len;
		while (l < r)
		{
			int mid = l + r  + 1 >> 1;
			if (q[mid] < a[i]) l = mid;
			else r = mid - 1;
		}
		// r ���ز����� a[i] �������������βԪ�ص����ֵ 
		len = max(len, r + 1);
		q[r + 1] = a[i];
	}
	
	cout << len << endl;
	
	return 0;
}
