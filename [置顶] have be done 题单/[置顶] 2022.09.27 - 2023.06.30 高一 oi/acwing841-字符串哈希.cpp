#include <iostream>

using namespace std;

typedef unsigned long long ULL;

const int N = 1e5 + 10, P = 131;
// P 表示 P 进制，或取 13331
 
int n, m;
char str[N];
ULL h[N], p[N];
// h[i] 表示是字符串从 1 ~ i 的哈希值 
// p[i] 表示 P 的 i 次方 

ULL get(int l, int r)
{
	return h[r] - h[l - 1] * p[r - l + 1];
}
// 计算字符串区间的哈希值 

int main()
{
	cin >> n >> m >> str + 1;
	
	p[0] = 1;
	for (int i = 1; i <= n; i ++)
	{
		p[i] = p[i - 1] * P;
		h[i] = h[i - 1] * P + str[i];
	}
	// 字符串哈希数组的初始化
	
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
