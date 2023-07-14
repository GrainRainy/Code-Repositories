#include <iostream>

using namespace std;

typedef unsigned long long ULL;

const int N = 1e5 + 10, P = 131;
// P ��ʾ P ���ƣ���ȡ 13331
 
int n, m;
char str[N];
ULL h[N], p[N];
// h[i] ��ʾ���ַ����� 1 ~ i �Ĺ�ϣֵ 
// p[i] ��ʾ P �� i �η� 

ULL get(int l, int r)
{
	return h[r] - h[l - 1] * p[r - l + 1];
}
// �����ַ�������Ĺ�ϣֵ 

int main()
{
	cin >> n >> m >> str + 1;
	
	p[0] = 1;
	for (int i = 1; i <= n; i ++)
	{
		p[i] = p[i - 1] * P;
		h[i] = h[i - 1] * P + str[i];
	}
	// �ַ�����ϣ����ĳ�ʼ��
	
	while (m --)
	{
		int l1, r1, l2 ,r2;
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		
		if (get(l1, r1) == get(l2, r2))
			cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	return 0;
}
